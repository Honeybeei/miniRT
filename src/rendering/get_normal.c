/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/07 20:32:41 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_vec3	normal_plane(t_line3 *sight_, t_figure *fg_);
static t_vec3	normal_sphere(t_pvec3 pos_, t_line3 *sight_, t_figure *fg_);
static t_vec3	normal_cylinder(t_pvec3 pos_, t_line3 *sight_, t_figure *fg_);

t_vec3	get_normal(t_pvec3 pos_, t_line3 sight_, t_figure *fg_)
{
	if (fg_->type_ == type_pl_)
		return (normal_plane(&sight_, fg_));
	else if (fg_->type_ == type_sp_)
		return (normal_sphere(pos_, &sight_, fg_));
	else if (fg_->type_ == type_cy_)
		return (normal_cylinder(pos_, &sight_, fg_));
	else
		return (regular_vec3(ZERO));
}

static t_vec3	normal_plane(t_line3 *sight_, t_figure *fg_)
{
	double	in_out;
	int		direction;

	in_out = dot_product(fg_->dir_, sight_->dir_);
	direction = (in_out < 0.0) - (0.0 < in_out);
	return (times_vec3(fg_->dir_, direction));
}

static t_vec3	normal_sphere(t_pvec3 pos_, t_line3 *sight_, t_figure *fg_)
{
	t_vec3	v_;
	double	in_out;
	int		direction;

	v_ = sub_vec3(pos_, fg_->pos_);
	in_out = dot_product(v_, sight_->dir_);
	direction = (in_out < 0.0) - (0.0 < in_out);
	return (times_vec3(normalize_vec3(v_), direction));
}

static t_vec3	normal_cylinder(t_pvec3 pos_, t_line3 *sight_, t_figure *fg_)
{
	t_vec3	v_;
	double	dval;
	int		in_out;

	v_ = sub_vec3(sight_->pos_, fg_->pos_);
	dval = dot_product(v_, fg_->dir_);
	in_out = ((0 < dval && dval < fg_->h_)
			&& (length_vec3(normal_vec3(v_, fg_->dir_)) < fg_->r_));
	dval = dot_product(sub_vec3(pos_, fg_->pos_), fg_->dir_);
	if (-0.00001 < dval && dval < 0.00001)
		return (times_vec3(fg_->dir_, in_out * 2 - 1));
	else if (fg_->h_ - 0.00001 < dval && dval < fg_->h_ + 0.00001)
		return (times_vec3(fg_->dir_, 1 - in_out * 2));
	else
		return (times_vec3(normalize_vec3(normal_vec3(sub_vec3(pos_
							, fg_->pos_), fg_->dir_)), 1 - in_out * 2));
}
