/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_unary_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:36:07 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:47:52 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minimath.h"

void	add_inverse_mtx3(t_mtx3 dst, t_mtx3 m)
{
	times_mtx3(dst, m, -1);
}

double	det_mtx3(t_mtx3 m)
{
	double	det;

	if (!m)
		escape();
	det = m[0][x_] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
	det += m[0][y_] * (m[1][2] * m[2][0] - m[1][0] * m[2][2]);
	det += m[0][z_] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	return (det);
}

void	transpose_mtx3(t_mtx3 dst, t_mtx3 m)
{
	t_mtx3	tmp;
	size_t	i;
	size_t	j;

	if (!(dst && m))
		escape();
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			tmp[i][j] = m[j][i];
			j++;
		}
		i++;
	}
	input_mtx3(dst, tmp[0], tmp[1], tmp[2]);
}

static void	cofactor_mtx3(double *e, size_t i, size_t j, t_mtx3 m)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	a = (j + 1) % 3;
	b = (i + 1) % 3;
	c = (j + 2) % 3;
	d = (i + 2) % 3;
	*e = m[a][b] * m[c][d] - m[a][d] * m[c][b];
}

void	inverse_mtx3(t_mtx3 dst, t_mtx3 m)
{
	t_mtx3	tmp;
	double	det;
	size_t	i;
	size_t	j;

	det = det_mtx3(m);
	if (!det && printf("[exception] : param_matrix is not invertible\n"))
		return ;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			cofactor_mtx3(&tmp[i][j], i, j, m);
			j++;
		}
		i++;
	}
	times_mtx3(dst, tmp, 1 / det);
}
