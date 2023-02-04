/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:06:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 02:43:50 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	object_traverse(t_objs *objs_, t_line3 sight_, t_cpnt *contact_)
{
	t_figure	*fg_;
	size_t		i;

	i = 0;
	while (i < objs_->figure_cnt_)
	{
		fg_ = objs_->figures_ + i++;
		if (fg_->type_ == type_pl_)
			check_plane(fg_, sight_, contact_);
		else if (fg_->type_ == type_sp_)
			check_sphere(fg_, sight_, contact_);
		else if (fg_->type_ == type_cy_)
			check_cylinder(fg_, sight_, contact_);
	}
	if (contact_->fg_->type_ == type_pl_ && 500 < contact_->tmin)
		contact_->ismeet_ = false; // pl_t 원경 문제 해결!
	return (contact_->ismeet_);
}

void	check_plane(t_figure *fg_, t_line3 sight_, t_cpnt *ct_)
{
	t_vec3	eq_;
	double	tval;

	eq_.e[2] = 0;
	eq_.e[1] = dot_product(fg_->dir_, sight_.dir_);
	eq_.e[0] = dot_product(fg_->dir_, sub_vec3(sight_.pos_, fg_->pos_));
	if (positive_solution(eq_, &tval))
		tmin_update(fg_, sight_, ct_, tval);
}

void	check_sphere(t_figure *fg_, t_line3 sight_, t_cpnt *ct_)
{
	t_vec3	tmp_;
	t_vec3	eq_;
	double	tval;

	tmp_ = sub_vec3(sight_.pos_, fg_->pos_);
	eq_.e[0] = sqrsum_vec3(tmp_) - fg_->r_ * fg_->r_;
	eq_.e[1] = dot_product(sight_.dir_, tmp_) * 2;
	eq_.e[2] = sqrsum_vec3(sight_.dir_);
	if (positive_solution(eq_ ,&tval))
		tmin_update(fg_, sight_, ct_, tval);
}

void	check_cylinder(t_figure *fg_, t_line3 sight_, t_cpnt *ct_)
{
	double	t[2];
	double	dist[2];
	double	cos;
	t_line3	infinite_cyl;
	t_vec3	oncyl[2];
	double	tmp;
	double	det[2];
	t_line3	sol;
	double	tval;

	//	평행한 경우는 다르게 계산해야합니다.
	infinite_cyl = init_line3(fg_->pos_, fg_->dir_);
	dist[0] = dist_line_line(infinite_cyl, sight_);
	if (fg_->r_ < dist[0])
		return ;	
	if (isparallel_vec3(fg_->dir_, sight_.dir_))
	{
		if (0 < dot_product(fg_->dir_, sub_vec3(sight_.pos_, fg_->pos_)))
			sol_line3_plane3(sight_, fg_->p_low_, &sol, &tval);
		else
			sol_line3_plane3(sight_, fg_->p_low_, &sol, &tval);
		if (dist_dot_line(sol.pos_, infinite_cyl) <= fg_->r_)
			tmin_update(fg_, sight_, ct_, tval);
		return ;
	}
	dist[1] = dist_dot_line(sight_.pos_, infinite_cyl);
	cos = fabs(tocos_vec3(sight_.dir_, fg_->dir_));
	t[0] = sqrt((pow(dist[1], 2) - pow(dist[0], 2)) / (1 - pow(cos, 2)));
	t[1] = sqrt((pow(fg_->r_, 2) - pow(dist[0], 2)) / (1 - pow(cos, 2)));
	oncyl[0] = add_vec3(sight_.pos_, times_vec3(sight_.dir_, t[0] - t[1]));
//	oncyl[1] = add_vec3(sight_.pos_, times_vec3(sight_.dir_, t[0] + t[1]));
	tmp = dot_product(sub_vec3(oncyl[0], fg_->pos_), fg_->dir_);
	det[0] = (fg_->h_ < tmp) - (tmp < 0);
//	tmp = dot_product(sub_vec3(oncyl[1], fg_->pos_), fg_->dir_);
//	det[1] = (fg_->h_ < tmp) - (tmp < 0);
	if (det[0] == 0)
		tmin_update(fg_, sight_, ct_, t[0] - t[1]);
	else if (det[0] < 0 && sol_line3_plane3(sight_, fg_->p_low_, &sol, &tval))
		tmin_update(fg_, sight_, ct_, t[0] - t[1]);
	else if (0 < det[0] && sol_line3_plane3(sight_, fg_->p_high_, &sol, &tval))
		tmin_update(fg_, sight_, ct_, t[0] - t[1]);
}

// 	1. 되면 채택 tmin_update
	// 요 값이 H-range에 포함되는가?
	// 	1. 되면 채택 tmin_update
	//	2. 안되면 뚜껑, 바닥 확인
	//		1.2. 되는쪽으로, 둘다 되면 작은쪽으로 tmin_update

// ㅅㅂ 실린더는 계산이 아예 다르네.. -> 사실 걍 쓴 접근법이 달라서 그럼
void	tmin_update(t_figure *fg_, t_line3 sight_, t_cpnt *ct_, double tval)
{
	if (ct_->ismeet_ == true_ && ct_->tmin < tval)
		return ;
	ct_->tmin = tval;
	ct_->ismeet_ = true_;
	ct_->pos_ = add_vec3(sight_.pos_, times_vec3(sight_.dir_, tval));
	ct_->fg_ = fg_;
}
