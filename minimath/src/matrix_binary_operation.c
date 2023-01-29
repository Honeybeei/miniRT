/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_binary_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:48:22 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/30 00:21:11 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_mtx3	add_mtx3(t_mtx3 m1, t_mtx3 m2)
{
	t_mtx3	m;

	m.r[0] = add_vec3(m1.r[0], m2.r[0]);
	m.r[1] = add_vec3(m1.r[1], m2.r[1]);
	m.r[2] = add_vec3(m1.r[2], m2.r[2]);
	return (m);
}

t_mtx3	add_inverse_mtx3(t_mtx3 m)
{
	return (times_mtx3(m, -1.0));
}

t_mtx3	sub_mtx3(t_mtx3 m1, t_mtx3 m2)
{
	return (add_mtx3(m1, add_inverse_mtx3(m2)));
}

t_mtx3	mul_mtx3(t_mtx3 m1, t_mtx3 m2)
{
	t_mtx3	tmp;
	double	e[3];
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			e[j] = 0;
			k = 0;
			while (k < 3)
			{
				e[j] += (m1.r[i].e[k] * m2.r[k].e[j]);
				k++;
			}
			j++;
		}
		tmp.r[i] = init_vec3(e[x_], e[y_], e[z_]);
		i++;
	}
	return (tmp);
}

t_mtx3	pow_mtx3(t_mtx3 m, int times)
{
	t_mtx3	tmp;
	t_mtx3	exp;

	tmp = regular_mtx3(IDENTITY);
	exp = m;
	if (times < 0)
	{
		if (!det_mtx3(m) && printf("param matrix is not inversible\n"))
			return (m);
		exp = inverse_mtx3(exp);
	}
	while (times != 0)
	{
		tmp = mul_mtx3(tmp, exp);
		times += ((times < 0) - (0 < times));
	}
	return (tmp);
}
