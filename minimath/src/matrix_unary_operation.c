/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_unary_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:48:10 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/30 00:21:14 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_mtx3	times_mtx3(t_mtx3 m, double scalar)
{
	m.r[0] = times_vec3(m.r[0], scalar);
	m.r[1] = times_vec3(m.r[1], scalar);
	m.r[2] = times_vec3(m.r[2], scalar);
	return (m);
}

t_mtx3	transpose_mtx3(t_mtx3 m)
{
	t_mtx3	tmp;
	size_t	i;

	i = 0;
	while (i < 3)
	{
		tmp.r[i] = init_vec3(m.r[x_].e[i], m.r[y_].e[i], m.r[z_].e[i]);
		i++;
	}
	return (tmp);
}

static double	cofactor_mtx3(size_t i, size_t j, t_mtx3 m)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	a = (i + 1) % 3;
	b = (j + 1) % 3;
	c = (i + 2) % 3;
	d = (j + 2) % 3;
	return (m.r[a].e[b] * m.r[c].e[d] - m.r[a].e[d] * m.r[c].e[b]);
}

double	det_mtx3(t_mtx3 m)
{
	double	det;

	det = m.r[0].e[x_] * cofactor_mtx3(0, x_, m);
	det += m.r[0].e[y_] * cofactor_mtx3(0, y_, m);
	det += m.r[0].e[z_] * cofactor_mtx3(0, z_, m);
	return (det);
}

t_mtx3	inverse_mtx3(t_mtx3 m)
{
	t_mtx3	tmp;
	double	det;
	double	e[3];
	size_t	i;
	size_t	j;

	det = det_mtx3(m);
	if (!det && printf("[exception] : param_matrix is not invertible\n"))
		return (m);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			e[j] = cofactor_mtx3(j, i, m);
			j++;
		}
		tmp.r[i++] = init_vec3(e[x_], e[y_], e[z_]);
	}
	return (times_mtx3(tmp, 1 / det));
}
