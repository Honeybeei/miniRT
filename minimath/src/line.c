/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:38 by jchoi             #+#    #+#             */
/*   Updated: 2023/02/05 02:49:06 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_line3	init_line3(t_dot3 origin_, t_dvec3 dir_)
{
	t_line3	ret_;
	
	ret_.pos_ = origin_;
	ret_.dir_ = normalize_vec3(dir_);
	return (ret_);
}

t_line3	line3_by_dots(t_dot3 origin_, t_dot3 dst_)
{
	return (init_line3(origin_, sub_vec3(dst_, origin_)));
}

t_plane3	init_plane3(t_dot3 origin_, t_dvec3 dir_)
{
	t_plane3	p_;

	p_.pos_ = origin_;
	p_.dir_ = dir_;
	return (p_);
}
int		sol_line3_plane3(t_line3 l_, t_plane3 p_, t_line3 *sol_, double *tval);

double	dist_dot_dot(t_dot3 a, t_dot3 b)
{
	return (length_vec3(sub_vec3(a, b)));
}

double	dist_dot_line(t_dot3 a, t_line3 l_)
{
	return (length_vec3(normal_vec3(sub_vec3(a, l_.pos_), l_.dir_)));
}

double	dist_dot_plane(t_dot3 a, t_plane3 p)
{
	return (length_vec3(tangent_vec3(sub_vec3(p.pos_, a), p.dir_)));
}

double	tocos_vec3(t_vec3 u, t_vec3 v)
{
	return (dot_product(u, v) / (length_vec3(u) * length_vec3(v)));
}

int	isparallel_vec3(t_vec3 u, t_vec3 v)
{
	return (fabs(tocos_vec3(u,v)) == 1.0);
}

int	isperpendic_vec3(t_vec3 u, t_vec3 v)
{
	return (tocos_vec3(u,v) == 0.0);
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

t_dot3	dot_on_line3(t_line3 l_, double tval)
{
	return (add_vec3(l_.pos_, times_vec3(l_.dir_, tval)));
}

int	sol_line3_plane3(t_line3 l_, t_plane3 p_, t_line3 *sol_, double *tval)
{
	double	cos;
	
	cos = fabs(tocos_vec3(l_.dir_, p_.dir_));
	if (cos == 0.0)
	{
//		if (dist_dot_plane(l_.pos_, p_) == 0.0)
//		{
//			*sol_ = l_;
//			return (true_);
//		}
//		else
			return (0);
	}
	else
	{
		sol_->dir_ = regular_vec3(ZERO);
		*tval = dist_dot_plane(l_.pos_, p_) / cos;
		sol_->pos_ = dot_on_line3(l_, *tval);
		return (1);
	}
}
