/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_vec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:58:03 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/30 00:21:06 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_VEC_H
# define STRUCT_VEC_H

// 2d vector
typedef struct s_2d_vector
{
	double	e[2];
}	t_vec2;

// 3d vector
typedef struct s_3d_vector
{
	double	e[3];
}	t_vec3;

// position vector
typedef t_vec2	t_pvec2;
typedef t_vec3	t_pvec3;

// directional vector
typedef t_vec2	t_dvec2;
typedef t_vec3	t_dvec3;

// matrix
typedef struct s_2d_matrix
{
	t_vec2	r[2];
}	t_mtx2;

typedef struct s_3d_matrix
{
	t_vec3	r[3];
}	t_mtx3;

typedef enum e_xyz
{
	x_ = 0,
	y_ = 1,
	z_ = 2
}	t_xyz;

#endif
