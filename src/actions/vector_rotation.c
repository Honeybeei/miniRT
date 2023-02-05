/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:47:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 18:49:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static double	get_rotated_x(t_vec3 orientation, t_dvec3 rot_axis, double rad);
static double	get_rotated_y(t_vec3 orientation, t_dvec3 rot_axis, double rad);
static double	get_rotated_z(t_vec3 orientation, t_dvec3 rot_axis, double rad);

t_vec3	rotate_vector(t_vec3 vec_to_rotate, t_vec3 rot_axis, double degree)
{
	t_vec3	result;
	double	rad;

	rad = deg_to_rad(degree);
	result.e[x_] = get_rotated_x(vec_to_rotate, rot_axis, rad);
	result.e[y_] = get_rotated_y(vec_to_rotate, rot_axis, rad);
	result.e[z_] = get_rotated_z(vec_to_rotate, rot_axis, rad);
	return (result);
}

static double	get_rotated_x(t_vec3 orientation, t_dvec3 rot_axis, double rad)
{
	double	x_calc_result;
	double	y_calc_result;
	double	z_calc_result;

	x_calc_result = orientation.e[x_] * (cos(rad) + rot_axis.e[x_] * \
	rot_axis.e[x_] * (1 - cos(rad)));
	y_calc_result = orientation.e[y_] * (rot_axis.e[x_] * rot_axis.e[y_] * \
	(1 - cos(rad)) + rot_axis.e[z_] * sin(rad));
	z_calc_result = orientation.e[z_] * (rot_axis.e[x_] * rot_axis.e[z_] * \
	(1 - cos(rad)) - rot_axis.e[y_] * sin(rad));
	return (x_calc_result + y_calc_result + z_calc_result);
}

static double	get_rotated_y(t_vec3 orientation, t_dvec3 rot_axis, double rad)
{
	double	x_calc_result;
	double	y_calc_result;
	double	z_calc_result;

	x_calc_result = orientation.e[x_] * (rot_axis.e[x_] * rot_axis.e[y_] * \
	(1 - cos(rad)) - rot_axis.e[z_] * sin(rad));
	y_calc_result = orientation.e[y_] * (cos(rad) + rot_axis.e[y_] * \
	rot_axis.e[y_] * (1 - cos(rad)));
	z_calc_result = orientation.e[z_] * (rot_axis.e[y_] * rot_axis.e[z_] * \
	(1 - cos(rad)) + rot_axis.e[x_] * sin(rad));
	return (x_calc_result + y_calc_result + z_calc_result);
}

static double	get_rotated_z(t_vec3 orientation, t_dvec3 rot_axis, double rad)
{
	double	x_calc_result;
	double	y_calc_result;
	double	z_calc_result;

	x_calc_result = orientation.e[x_] * (rot_axis.e[x_] * rot_axis.e[z_] * \
	(1 - cos(rad)) + rot_axis.e[y_] * sin(rad));
	y_calc_result = orientation.e[y_] * (rot_axis.e[y_] * rot_axis.e[z_] * \
	(1 - cos(rad)) - rot_axis.e[x_] * sin(rad));
	z_calc_result = orientation.e[z_] * (cos(rad) + rot_axis.e[z_] * \
	rot_axis.e[z_] * (1 - cos(rad)));
	return (x_calc_result + y_calc_result + z_calc_result);
}
