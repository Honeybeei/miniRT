/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:47:58 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/30 00:21:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_mtx3	init_mtx3(t_vec3 v0, t_vec3 v1, t_vec3 v2)
{
	t_mtx3	m;

	m.r[0] = v0;
	m.r[1] = v1;
	m.r[2] = v2;
	return (m);
}

t_mtx3	regular_mtx3(int type)
{
	t_mtx3	m;

	m.r[0] = init_vec3(type == IDENTITY, 0, 0);
	m.r[1] = init_vec3(0, type == IDENTITY, 0);
	m.r[2] = init_vec3(0, 0, type == IDENTITY);
	return (m);
}

void	print_mtx3(t_mtx3 m)
{
	print_vec3(m.r[0]);
	print_vec3(m.r[1]);
	print_vec3(m.r[2]);
}
