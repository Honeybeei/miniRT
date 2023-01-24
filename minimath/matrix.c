/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:34:51 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:35:40 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimath.h"

void	input_mtx3(t_mtx3 dst, t_vec3 v0, t_vec3 v1, t_vec3 v2)
{
	if (!(dst && v0 && v1 && v2))
		escape();
	input_vec3(dst[0], v0[x_], v0[y_], v0[z_]);
	input_vec3(dst[1], v1[x_], v1[y_], v1[z_]);
	input_vec3(dst[2], v2[x_], v2[y_], v2[z_]);
}

void	print_mtx3(t_mtx3 m)
{
	if (!m)
		escape();
	print_vec3(m[0]);
	print_vec3(m[1]);
	print_vec3(m[2]);
}

void	regular_mtx3(t_mtx3 m, const int type)
{
	t_vec3	v[3];

	if (!m)
		escape();
	else if ((type < ZERO || IDENTITY < type) && printf("invalid type\n"))
		return ;
	input_vec3(v[0], type == IDENTITY, 0, 0);
	input_vec3(v[1], 0, type == IDENTITY, 0);
	input_vec3(v[2], 0, 0, type == IDENTITY);
	input_mtx3(m, v[0], v[1], v[2]);
}
