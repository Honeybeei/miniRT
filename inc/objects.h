/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:41 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/26 12:36:25 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../minimath/inc/struct_vec3.h"
# include <stdlib.h>	// size_t

typedef int t_color;

typedef struct s_ray
{
	t_pvec3	origin_;
	t_dvec3	direction_;
	t_color	color_;
	size_t	hit_cnt_;
}	t_ray;

typedef struct s_camera
{
	t_pvec3	view_point_;
	t_dvec3	orientation_;
	int		fov_;
}	t_camera;

typedef struct s_screen
{
	t_pvec3	center_;
	t_dvec3	normal_vec_;
	size_t	width_;
	size_t	height_;
}	t_screen;

typedef struct s_sphere
{
	t_pvec3	center_;
	double	diameter_;
	t_color	color_;
}	t_sphere;

// TODO : light, plane, cylinder

#endif