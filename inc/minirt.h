/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/23 18:35:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ************************************************************************** */

# include <fcntl.h>	//	open(),
# include <stdio.h>	//	perror(),

// archived files
# include "../my_lib/inc/improved_libft.h"
# include "../my_lib/inc/get_next_line.h"
# include "../mlx/mlx.h"

// enums, struct and etc
# include "mlx_related.h"
# include "elements.h"

/* ************************************************************************** */

//  Customized boolean to increase readability.
typedef enum e_my_boolean
{
	fail_ = 0,
	success_,
	invalid_ = 0,
	valid_
}	t_bool;

//	Customized flag to in crease readability.
typedef enum e_flag
{
	down_ = -1,
	up_ = 1
}	t_flag;

/**
 * customized error number. It will be pared up with error_msg defined in 
 * error_management.c
 */
typedef enum e_customized_errno
{
	err_no_file_ = 0,
	err_too_much_file_,
	err_invalid_input_data_
}	t_errno;

/* ************************************************************************** */

// Ultimate pointer in this project
typedef struct s_minirt_ptrs
{
	t_mlx	mlx_;
	t_img	img_;
	t_input	input_;
}	t_ptrs;

/* ************************************************************************** */

// input_management

//		parse_input.c
void	parse_input(t_input *input, char *src);

//		parsing_utils1.c
double	my_strtod(const char *nptr);  // Currently using strtod from stdlib. Need to be fixed. 
bool	is_valid_double_format(char *num_str);
bool	is_valid_int_format(char *num_str);
bool	is_in_range(double target, double min, double max);

//		parsing_utils2.c
t_bool	parse_rgb(t_rgb *dst, char *rgb_data);
t_bool	parse_vec3(t_vec3 *dst, bool is_orientation_vec, char *vec_data);

//		scan_formats1.c
void	scan_single_line(t_input *input, char *input_str);
void	scan_ambient_format(t_input_a *ambient, char **str_arr);
void	scan_camera_format(t_input_c *camera, char **str_arr);
void	scan_light_format(t_input_l *light, char **str_arr);
void	scan_sphere_format(t_input_sp **sphere_arr, char **str_arr);
void	scan_plane_format(t_input_pl **plane_arr, char **str_arr);
void	scan_cylinder_format(t_input_cy **cylinder_arr, char **str_arr);

/* ************************************************************************** */

//	utils

//		error_management.c
void	error_management(bool is_customized_err, t_errno customized_errno, \
		char *additional_err_msg, bool should_exit);

//		hello_world.c -> only for test. THIS should be deleted.
void	hello_world(int n);

//		initialization.c
void	init_ptrs(t_ptrs *ptrs);
void	init_mlx(t_ptrs *ptrs);
int		handle_key_press_event(int key_code, t_ptrs *ptrs);

/* ************************************************************************** */

#endif