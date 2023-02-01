/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:41 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 13:36:57 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

/* ************************************************************************** */

# include "../minimath/inc/struct_vec.h"
# include <stdlib.h>	// size_t

/* ************************************************************************** */

typedef int	t_color;
typedef	t_vec3	t_rgb;

typedef struct s_ambient
{
	double	ratio_;
	int		color_;
}	t_ambient;

typedef struct s_ray
{
	t_pvec3	origin_;
	t_dvec3	direction_;
	t_color	color_;
	int		hit_cnt_;
}	t_ray;

typedef struct s_camera
{
	t_pvec3	pos_;
	t_dvec3	dir_;
	double	fov_;
}	t_camera;

typedef struct s_screen
{
	t_pvec3	center_;
	t_pvec3	start_;
	t_vec3	hor_unit_;
	t_vec3	ver_unit_;
}	t_screen;

typedef struct s_light
{
	t_pvec3	light_point_;
	double	ratio_;
	t_color	color_;
}	t_light;

typedef struct s_sphere
{
	// TODO
}	t_sp;

typedef struct s_cylinder
{
	// TODO
}	t_cy;

typedef struct s_plane
{
	// TODO
}	t_pl;

/* ************************************************************************** */

typedef enum e_figure_type
{
	type_none_ = 0,
	type_pl_,
	type_sp_,
	type_cy_
}	t_type;

typedef struct s_figure
{
	t_type	type_;
	t_color	clr_;
	t_pvec3	pos_;
	t_dvec3	dir_;
	double	r_;
	double	h_;
	void	*obj_;
}	t_figure;

/* ************************************************************************** */

typedef struct s_objects
{
	t_ambient	ambient_;
	t_camera	camera_;
	t_screen	screen_;
	t_light		*lights_;
	size_t		light_cnt_;
	t_figure	*figures_;
	size_t		figure_cnt_;
}	t_objs;

/* ************************************************************************** */

#endif
