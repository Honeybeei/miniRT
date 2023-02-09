/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/10 00:05:39 by jchoi            ###   ########.fr       */
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
	{
		printf("mooyaho");
		return (regular_vec3(ZERO));
	}
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
		return (times_vec3(normalize_vec3(normal_vec3(sub_vec3(pos_, \
		fg_->pos_), fg_->dir_)), 1 - in_out * 2));
}

int	checkered_sphere(t_cpnt *contact_)
{
	t_vec3	v_;
	double	theta;
	double	angular;
	int		checker;

	v_ = normalize_vec3(sub_vec3(contact_->pos_, contact_->fg_->pos_));
	theta = acos(v_.e[y_]);
	if (sin(theta) == 0)
		return (0);
	angular = acos(v_.e[z_] / sin(theta));
	checker = pow(-1, (0 < v_.e[x_]) + (int)(angular / M_PI_4)
			+ (int)(theta / (M_PI / 6)));
	contact_->rgb_ = add_vec3(init_vec3(125, 125, 125),
			times_vec3(init_vec3(105, 105, 105), checker));
	return (1);
}
