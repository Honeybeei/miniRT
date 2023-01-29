/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_binary_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:47:14 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/30 00:21:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_vec3	add_vec3(t_vec3 v, t_vec3 v2)
{
	v.e[x_] += v2.e[x_];
	v.e[y_] += v2.e[y_];
	v.e[z_] += v2.e[z_];
	return (v);
}

t_vec3	sub_vec3(t_vec3 v, t_vec3 v2)
{
	return (add_vec3(v, inverse_vec3(v2)));
}

double	dot_product(t_vec3 v1, t_vec3 v2)
{
	double	ret;

	ret = v1.e[x_] * v2.e[x_];
	ret += v1.e[y_] * v2.e[y_];
	ret += v1.e[z_] * v2.e[z_];
	return (ret);
}

t_vec3	cross_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v;

	v.e[x_] = v1.e[y_] * v2.e[z_] - v1.e[z_] * v2.e[y_];
	v.e[y_] = v1.e[z_] * v2.e[x_] - v1.e[x_] * v2.e[z_];
	v.e[z_] = v1.e[x_] * v2.e[y_] - v1.e[y_] * v2.e[x_];
	return (v);
}
