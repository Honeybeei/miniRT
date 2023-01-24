/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_vec3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:58:03 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 21:29:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_VEC3_H
# define STRUCT_VEC3_H

// 3d vector
typedef double	t_vec3[3];

// position vector
typedef t_vec3	t_pvec3;

// directional vector
typedef t_vec3	t_dvec3;

// 3*3 matrix
typedef t_vec3	t_mtx3[3];

typedef enum e_xyz
{
	x_ = 0,
	y_ = 1,
	z_ = 2
}	t_xyz;

#endif