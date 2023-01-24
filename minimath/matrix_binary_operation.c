/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_binary_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:36:23 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:40:07 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minimath.h"

void	add_mtx3(t_mtx3 dst, t_mtx3 m1, t_mtx3 m2)
{
	if (!(dst && m1 && m2))
		escape();
	add_vec3(dst[0], m1[0], m2[0]);
	add_vec3(dst[1], m1[1], m2[1]);
	add_vec3(dst[2], m1[2], m2[2]);
}

void	times_mtx3(t_mtx3 dst, t_mtx3 m, const double scalar)
{
	if (!(dst && m))
		escape();
	times_vec3(dst[0], m[0], scalar);
	times_vec3(dst[1], m[1], scalar);
	times_vec3(dst[2], m[2], scalar);
}

void	sub_mtx3(t_mtx3 dst, t_mtx3 m1, t_mtx3 m2)
{
	t_mtx3	sub;

	add_inverse_mtx3(sub, m2);
	add_mtx3(dst, m1, sub);
}

void	mul_mtx3(t_mtx3 dst, t_mtx3 m1, t_mtx3 m2)
{
	t_mtx3	tmp;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!(dst && m1 && m2))
		escape();
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			tmp[i][j] = 0;
			k = 0;
			while (k < 3)
			{
				tmp[i][j] += (m1[i][k] * m2[k][j]);
				k++;
			}
			j++;
		}
		i++;
	}
	input_mtx3(dst, tmp[0], tmp[1], tmp[2]);
}

void	pow_mtx3(t_mtx3 dst, t_mtx3 m, int times)
{
	t_mtx3	tmp;
	t_mtx3	exp;

	regular_mtx3(tmp, IDENTITY);
	input_mtx3(exp, m[0], m[1], m[2]);
	if (times < 0)
	{
		if (!det_mtx3(m) && printf("param matrix is not inversible\n"))
			return ;
		inverse_mtx3(exp, exp);
	}
	while (times != 0)
	{
		mul_mtx3(tmp, tmp, exp);
		times += ((times < 0) - (0 < times));
	}
	input_mtx3(dst, tmp[0], tmp[1], tmp[2]);
}
