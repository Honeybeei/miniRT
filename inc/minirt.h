/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 20:53:39 by jchoi            ###   ########.fr       */
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
# include "../minimath/inc/minimath.h"

// etc
# include "actions.h"
# include "color.h"
# include "input.h"
# include "mlx_related.h"
# include "my_booleans.h"
# include "my_errno.h"
# include "my_flag.h"
# include "objects.h"
# include "rendering.h"
# include "user_interface.h"

/* ************************************************************************** */

// Ultimate pointer in this project
typedef struct s_minirt_ptrs
{
	t_mlx	mlx_;
	t_img	img_;
	t_objs	objs_;
}	t_ptrs;

/* ************************************************************************** */

//	actions

//		action_handling.c
void	mlx_hooks(t_ptrs *ptrs);

//		ambient_cntl_mode_actions.c
void	ambient_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs);

//		camera_cntl_mode_actions.c
void	camera_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs);

//		figure_cntl_mode_actions.c
void	figure_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs);

//		light_cntl_mode_actions.c
void	light_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs);

//		normal_mode_actions.c
void	normal_mode_key_press_event(int key_code, t_ptrs *ptrs);

//		vector_rotation.c
t_vec3	rotate_vector(t_vec3 vec_to_rotate, t_vec3 rot_axis, double degree);
// t_vec3	rotate_horizontally(t_vec3 orientation, double degree);
// t_vec3	rotate_vertically(t_vec3 orientation, double degree);

/* ************************************************************************** */

//	drawing_tools

//		color_related.c
t_color	element_to_color(double r, double g, double b);
t_color	rgb_to_color(t_rgb rgb);
t_rgb	color_to_rgb(t_color clr);
int		color_to_element(t_color clr, char type);

//		print_all.c
void	print_screen(t_ptrs *ptrs, bool should_rerender);

//		print_ambient_cntl.c
void	print_ambient_light_cntl_mode_ui(t_ptrs *ptrs);

//		print_box.c
void	print_spec_with_box(t_mlx *mlx, char **info_str_arr, int line_cnt);

//		print_camera_cntl.c
void	print_camera_cntl_mode_ui(t_ptrs *ptrs);

//		print_figure_cntl.c
void	print_figure_cntl_mode_ui(t_ptrs *ptrs);

//		print_light_cntl.c
void	print_light_cntl_mode_ui(t_ptrs *ptrs);

//		print_normal.c
void	print_normal_mode_ui(t_ptrs *ptrs);

//		print_utils.c
char	*vec3_to_str(t_vec3 vec, int precision);
char	*join_str_and_vector(char *str, t_vec3 vec, int precision);
char	*join_str_and_double(char *str, double n, int precision);
char	*get_bracketed_int(t_bracket_type type, int n);

//		put.c
void	put_pixel(t_img *img, int i, int j, t_color color);

/* ************************************************************************** */

//	input_parsing

//		parse_input.c
void	parse_input(t_objs *objs, char *src_file);

//		parsing_utils1.c
char	*get_next_line_without_new_line(int fd);
bool	is_valid_double_format(char *num_str);
bool	is_valid_int_format(char *num_str);
bool	is_in_range(double target, double min, double max);

//		parsing_utils2.c
t_bool	parse_rgb(t_color *dst, char *rgb_data);
t_bool	parse_vec3(t_vec3 *dst, bool is_orientation_vec, char *vec_data);
t_bool	is_valid_spec_cnt(char **str_arr, int expected_cnt);
void	free_str_arr(char **str_arr);

//		print_inputs.c
void	print_inputs(t_objs *objs);

//		scan_essentials.c
void	scan_ambient_lightning(t_ambient *ambient, char **str_arr);
void	scan_camera(t_camera *camera, char **str_arr);
void	scan_light(t_light *light, char **str_arr);

//		scan_optionals.c
void	scan_figures(t_figure *figure, char **splitted_str);

/* ************************************************************************** */

//	rendering

//		draw_all.c
void	draw_all(t_mlx *mlx_, t_img *img_, t_objs *objs_);
t_dot3	set_screen(t_screen *screen_, t_camera camera_);
t_color	process_pixel(t_objs *objs_, t_line3 sight_, size_t	y);
t_vec3	get_normal(t_pvec3 pos_, t_line3 sight_, t_figure *fg_);
void	get_light(t_objs *objs_, size_t i, t_line3 sight_, t_cpnt *contact_);


//		traverse.c
t_bool	object_traverse(t_objs *objs_, t_line3 sight_, t_cpnt *contact_);
void	check_plane(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
void	check_sphere(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
void	tmin_update(t_figure *fg_, t_line3 sight_, t_cpnt *ct_, double tval);

/* ************************************************************************** */
//	utils

//		error_management.c
void	error_management(bool is_customized_err, t_errno customized_errno, \
		char *additional_err_msg, bool should_exit);

//		initialization.c
void	init_ptrs(t_ptrs *ptrs);

//		my_doubles.c
char	*my_dtostr(double n, int precision);
double	my_strtod(char *num_str);

/* ************************************************************************** */

#endif
