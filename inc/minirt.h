/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 13:14:39 by seoyoo           ###   ########.fr       */
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
void    normal_mode_key_press_event(int key_code, t_ptrs *ptrs);

/* ************************************************************************** */

//	drawing_tools

//		color_related.c
t_color	rgb_to_color(int r, int g, int b);
int		color_to_rgb(t_color color, char type);

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
void    print_light_cntl_mode_ui(t_ptrs *ptrs);

//		print_normal.c
void	print_normal_mode_ui(t_ptrs *ptrs);

//		print_utils.c
char	*vec3_to_str(t_vec3 vec, int precision);
char	*join_str_and_vector(char *str, t_vec3 vec, int precision);
char	*join_str_and_double(char *str, double n, int precision);
char	*get_bracketed_int(t_bracket_type type, int n);

//		put.c
void	put_pixel(t_img *img, int x, int y, t_color color);

/* ************************************************************************** */

//	input_parsing

//		parse_input.c
void	parse_input(t_objs *objs, char *src_file);

//		parsing_utils1.c
char	*get_next_line_without_new_line(int fd);
double	my_strtod(const char *nptr);
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

//	utils

//		error_management.c
void	error_management(bool is_customized_err, t_errno customized_errno, \
		char *additional_err_msg, bool should_exit);

//		initialization.c
void	init_ptrs(t_ptrs *ptrs);

//		my_doubles.c
char 	*my_dtostr(double n, int precision);

/* ************************************************************************** */

#endif