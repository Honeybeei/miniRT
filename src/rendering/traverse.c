/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:06:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/07 20:11:25 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	cy_sidecheck(t_figure *fg_, t_line3 *sight_, t_cpnt *con);


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
	if (positive_solution(eq_, &tval))
		tmin_update(fg_, sight_, ct_, tval);
}

void	check_cylinder(t_figure *fg_, t_line3 sight_, t_cpnt *ct_)
{
	t_vec3	eq_;
	double	tval[2];
	t_cpnt	tmp_;

	if (fg_->r_ < dist_line_line(((t_cy *)fg_->obj_)->axis_, sight_))
		return ;
	tmp_.tmin = 0;
	tmp_.ismeet_ = false_;
	eq_.e[2] = 0;
	eq_.e[1] = dot_product(fg_->dir_, sight_.dir_);
	eq_.e[0] = dot_product(fg_->dir_, sub_vec3(sight_.pos_, fg_->pos_));
	if (positive_solution(eq_, &tval[0]) &&	dist_dot_line(dot_on_line3(sight_
					, tval[0]), ((t_cy *)fg_->obj_)->axis_) < fg_->r_)
		tmin_update(fg_, sight_, &tmp_, tval[0]);
	eq_.e[1] = dot_product(fg_->dir_, sight_.dir_);
	eq_.e[0] = dot_product(fg_->dir_, sub_vec3(sight_.pos_
				, ((t_cy *)fg_->obj_)->top_.pos_));

	if (positive_solution(eq_, &tval[1]) && dist_dot_line(dot_on_line3(sight_
					, tval[1]), ((t_cy *)fg_->obj_)->axis_) < fg_->r_)
		tmin_update(fg_, sight_, &tmp_, tval[1]);
	cy_sidecheck(fg_, &sight_, &tmp_);
	if (0 < tmp_.tmin)
		tmin_update(fg_, sight_, ct_, tmp_.tmin);
}

static void	cy_sidecheck(t_figure *fg_, t_line3 *sight_, t_cpnt *con)
{
	t_vec3	x_[3];
	t_vec3	p_;
	t_vec3	d_;
	t_vec3	eq_;
	double	dval[2];
	
	x_[0] = sight_->pos_;
	x_[1] = sight_->dir_;
	p_ = fg_->pos_;
	d_ = fg_->dir_;
	x_[2] = sub_vec3(x_[0], p_);
	eq_.e[2] = sqrsum_vec3(x_[1]) - pow(dot_product(x_[1], d_), 2);
	eq_.e[1] = dot_product(x_[1], x_[2]) * 2;
	eq_.e[1] -= (dot_product(x_[1], d_) * dot_product(x_[2], d_)) * 2;
	eq_.e[0] = sqrsum_vec3(x_[2]);
	eq_.e[0] -= (pow(dot_product(x_[2], d_), 2) + pow(fg_->r_,2));
	if (positive_solution(eq_, &dval[0]))
	{
		dval[1] = dot_product(sub_vec3(dot_on_line3(*sight_, dval[0])
					, fg_->pos_), fg_->dir_);
		if (0 < dval[1] && dval[1] < fg_->h_)
			tmin_update(fg_, *sight_, con, dval[0]);
	}
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
