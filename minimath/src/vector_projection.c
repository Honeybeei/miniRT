/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:47:39 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/30 00:21:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

t_vec3	tangent_vec3(t_vec3 src, t_vec3 dir)
{
	return (times_vec3(dir, dot_product(src, normalize_vec3(dir))));
}

t_vec3	normal_vec3(t_vec3 src, t_vec3 dir)
{
	return (sub_vec3(src, tangent_vec3(src, dir)));
}
