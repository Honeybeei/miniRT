/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:06:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 21:31:19 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	check_cylinder(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
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
//	if (contact_->fg_->type_ == type_pl_ && 200 < contact_->tmin)
//		contact_->ismeet_ = false; // pl_t 원경 문제 해결!
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
	t_vec3	eq_;
	double	tval[4];
	
	if (fg_->r_ < dist_line_line(((t_cy *)fg_->obj_)->axis_, sight_))
		return ;
	tval[3] = -1;
	eq_.e[2] = 0;
	eq_.e[1] = dot_product(fg_->dir_, sight_.dir_);
	eq_.e[0] = dot_product(fg_->dir_, sub_vec3(sight_.pos_, fg_->pos_));
	if (positive_solution(eq_, &tval[0]) && 
	dist_dot_line(dot_on_line3(sight_, tval[0]), ((t_cy *)fg_->obj_)->axis_) < fg_->r_)
		tval[3] = tval[0];
	eq_.e[1] = dot_product(fg_->dir_, sight_.dir_);
	eq_.e[0] = dot_product(fg_->dir_, sub_vec3(sight_.pos_, ((t_cy *)fg_->obj_)->top_.pos_));
	if (positive_solution(eq_, &tval[1]) && dist_dot_line(dot_on_line3(sight_
		, tval[1]), ((t_cy *)fg_->obj_)->axis_) < fg_->r_ && tval[1] < tval[0])
		tval[3] = tval[1];

	t_vec3	X0 = sight_.pos_;
	t_vec3	X1 = sight_.dir_;
	t_vec3	P = fg_->pos_;
	t_vec3	D = fg_->dir_;
	t_vec3	X0_P = sub_vec3(X0, P);
	eq_.e[2] = sqrsum_vec3(X1) - pow(dot_product(X1, D), 2);
	eq_.e[1] = (dot_product(X1, X0_P) - dot_product(X1, D) * dot_product(X0_P, D))* 2;
	eq_.e[0] = sqrsum_vec3(X0_P) - pow(dot_product(X0_P, D), 2) - pow(fg_->r_,2);
	if (positive_solution(eq_, &tval[2]))
	{
		double d = dot_product(sub_vec3(dot_on_line3(sight_, tval[2]), fg_->pos_), fg_->dir_);
		if (0 < d && d < fg_->h_)
			tval[3] = tval[2];
	}
	if (0 < tval[3])
		tmin_update(fg_, sight_, ct_, tval[3]);
}

void	tmin_update(t_figure *fg_, t_line3 sight_, t_cpnt *ct_, double tval)
{
	if (ct_->ismeet_ == true_ && ct_->tmin < tval)
		return ;
	ct_->tmin = tval;
	ct_->ismeet_ = true_;
	ct_->pos_ = add_vec3(sight_.pos_, times_vec3(sight_.dir_, tval));
	ct_->fg_ = fg_;
}
