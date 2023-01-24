/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_unary_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:37:13 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:46:12 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minimath.h"

void	add_inverse_vec3(t_vec3 dst, t_vec3 v0)
{
	times_vec3(dst, v0, -1);
}

double	sqrsum_vec3(t_vec3 v)
{
	return (pow(v[x_], 2) + pow(v[y_], 2) + pow(v[z_], 2));
}

double	length_vec3(t_vec3 v)
{
	return (sqrt(sqrsum_vec3(v)));
}

void	normalize_vec3(t_vec3 dst, t_vec3 v)
{
	double	len;

	if (!(dst && v))
		escape();
	len = length_vec3(v);
	if (0 < len)
	{
		dst[x_] = v[x_] / len;
		dst[y_] = v[y_] / len;
		dst[z_] = v[z_] / len;
	}
	else
		printf("[normalize fail] : length of param vector is 0\n");
}
