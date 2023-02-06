/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:38 by jchoi             #+#    #+#             */
/*   Updated: 2023/02/07 02:25:30 by jchoi            ###   ########.fr       */
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

t_dot3	dot_on_line3(t_line3 l_, double tval)
{
	return (add_vec3(l_.pos_, times_vec3(l_.dir_, tval)));
}

t_plane3	init_plane3(t_dot3 origin_, t_dvec3 dir_)
{
	t_plane3	p_;

	p_.pos_ = origin_;
	p_.dir_ = normalize_vec3(dir_);
	return (p_);
}	
