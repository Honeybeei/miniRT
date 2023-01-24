/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_binary_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:37:33 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:37:37 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minimath.h"

void	add_vec3(t_vec3 dst, t_vec3 v1, t_vec3 v2)
{
	if (!(dst && v1 && v2))
		escape();
	dst[x_] = v1[x_] + v2[x_];
	dst[y_] = v1[y_] + v2[y_];
	dst[z_] = v1[z_] + v2[z_];
}

void	times_vec3(t_vec3 dst, t_vec3 v0, const double scalar)
{
	if (!(dst && v0))
		escape();
	dst[x_] = v0[x_] * scalar;
	dst[y_] = v0[y_] * scalar;
	dst[z_] = v0[z_] * scalar;
}

void	sub_vec3(t_vec3 v, t_vec3 v1, t_vec3 v2)
{
	t_vec3	sub;

	add_inverse_vec3(sub, v2);
	add_vec3(v, v1, sub);
}

double	dot_product(t_vec3 v1, t_vec3 v2)
{
	double	ret;

	if (!(v1 && v2))
		escape();
	ret = v1[x_] * v2[x_];
	ret += v1[y_] * v2[y_];
	ret += v1[z_] * v2[z_];
	return (ret);
}

void	cross_product(t_vec3 dst, t_vec3 v1, t_vec3 v2)
{
	t_vec3	v;

	if (!(dst && v1 && v2))
		escape();
	v[x_] = v1[y_] * v2[z_] - v1[z_] * v2[y_];
	v[y_] = v1[z_] * v2[x_] - v1[x_] * v2[z_];
	v[z_] = v1[x_] * v2[y_] - v1[y_] * v2[x_];
	input_vec3(dst, v[x_], v[y_], v[z_]);
}
