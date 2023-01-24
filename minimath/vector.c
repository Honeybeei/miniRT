/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:36:57 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:36:59 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minimath.h"

void	input_vec3(t_vec3 dst, double x, double y, double z)
{
	if (!dst)
		escape();
	dst[x_] = x;
	dst[y_] = y;
	dst[z_] = z;
}

void	print_vec3(t_vec3 v)
{
	printf("x : %f\t", v[x_]);
	printf("y : %f\t", v[y_]);
	printf("z : %f\t", v[z_]);
	printf("\n");
}

void	regular_vec3(t_vec3 v, const int type)
{
	if ((type < ZERO || STD_Z < type) && printf("invalid type\n"))
		return ;
	input_vec3(v, type == STD_X, type == STD_Y, type == STD_Z);
}
