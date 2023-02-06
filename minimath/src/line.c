/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:38 by jchoi             #+#    #+#             */
/*   Updated: 2023/02/06 14:06:33 by seoyoo           ###   ########.fr       */
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
