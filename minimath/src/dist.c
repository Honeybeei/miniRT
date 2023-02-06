/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:38 by jchoi             #+#    #+#             */
/*   Updated: 2023/02/07 02:19:07 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

double	dist_dot_line(t_dot3 a, t_line3 l_)
{
	return (length_vec3(normal_vec3(sub_vec3(a, l_.pos_), l_.dir_)));
}

double	dist_dot_plane(t_dot3 a, t_plane3 p)
{
	return (fabs(dot_product(sub_vec3(p.pos_, a), p.dir_)));
}

double	dist_parallel_line(t_line3 l1_, t_line3 l2_)
{
	return (length_vec3(normal_vec3(sub_vec3(l1_.pos_, l2_.pos_), l1_.dir_)));
}

double	dist_skew_line(t_line3 l1_, t_line3 l2_)
{
	return (length_vec3(tangent_vec3(sub_vec3(l1_.pos_, l2_.pos_)
				, cross_product(l1_.dir_, l2_.dir_))));
}

double	dist_line_line(t_line3 l1_, t_line3	l2_)
{
	if (isparallel_vec3(l1_.dir_, l2_.dir_))
		return (dist_parallel_line(l1_, l2_));
	else
		return (dist_skew_line(l1_, l2_));
}
