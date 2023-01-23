/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:49:57 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/23 18:33:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

/* ************************************************************************** */

// WARNING!! THIS PART WILL BE REDEFINED IN JCHOI'S MATH LIBRARY. ERASE THIS 
// PART AFTER ADDING HEADER FILE OF THE NEW MATH LIBRARY. 

typedef double  t_vec3[3];
typedef t_vec3  t_pvec3;
typedef t_vec3  t_dvec3;

typedef t_vec3  t_mtx3[3];

typedef enum e_xyz
{
    x_ = 0,
    y_ = 1,
    z_ = 2
}   t_xyz;

/* ************************************************************************** */

// INPUT

# define INPUT_TYPE_CNT_ 6
# define INPUT_TYPE_FIRST_CHAR_ "ACLspc"

// This enum will be used in t_input to count elements.
enum e_input_type
{
	type_ambient_ = 0,
	type_camera_,
	type_light_,
	type_sphere_,
	type_plane_,
	type_cylinder_
};

typedef int	t_rgb[3];

enum e_rgb
{
	r_ = 0,
	g_,
	b_
};

typedef struct s_input_data_ambient_lightning
{
	double	ratio_;
	t_rgb	rgb_;
}	t_input_a;

typedef struct s_input_data_camera
{
	t_pvec3	view_point_;
	t_dvec3	orientation_;
	int		fov_;
}	t_input_c;

typedef struct s_input_light
{
	t_pvec3	light_point_;
	double	ratio_;
}	t_input_l;

typedef struct s_input_sphere
{
	t_pvec3	center_;
	double	diameter_;
	t_rgb	rgb_;
}	t_input_sp;

typedef struct s_input_plane
{
	t_pvec3	coordinate_;
	t_dvec3	orientation_;
	t_rgb	rgb_;
}	t_input_pl;

typedef struct s_input_cylinder
{
	t_pvec3	coordinate_;
	t_dvec3	orientation_;
	double	diameter_;
	double	height_;
	t_rgb	rgb_;
}	t_input_cy;

// input raw data
typedef struct s_input
{
	int			obj_cnt_[6];
	t_input_a	ambient_;
	t_input_c	camera_;
	t_input_l	light_;
	t_input_sp	*sphere_;
	t_input_pl	*plane_;
	t_input_cy	*cylinder_;
}	t_input;

/* ************************************************************************** */

#endif