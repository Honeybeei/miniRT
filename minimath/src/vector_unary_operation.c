/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_unary_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:47:26 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/30 00:21:30 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_vec3	times_vec3(t_vec3 v, double scalar)
{
	v.e[x_] *= scalar;
	v.e[y_] *= scalar;
	v.e[z_] *= scalar;
	return (v);
}

t_vec3	inverse_vec3(t_vec3 v)
{
	return (times_vec3(v, -1.0));
}

double	sqrsum_vec3(t_vec3 v)
{
	return (pow(v.e[x_], 2) + pow(v.e[y_], 2) + pow(v.e[z_], 2));
}

double	length_vec3(t_vec3 v)
{
	return (sqrt(sqrsum_vec3(v)));
}

t_vec3	normalize_vec3(t_vec3 v)
{
	double	len;

	len = length_vec3(v);
	if (len == 0.0)
	{
		printf("[normalize fail] : length of param vector is 0\n");
		return (v);
	}
	else
		return (times_vec3(v, 1.0 / len));
}
