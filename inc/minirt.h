/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 21:50:44 by seoyoo           ###   ########.fr       */
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
# include "input.h"
# include "mlx_related.h"
# include "my_booleans.h"
# include "my_errno.h"
# include "my_flag.h"
# include "objects.h"

/* ************************************************************************** */

// Ultimate pointer in this project
typedef struct s_minirt_ptrs
{
	t_mlx	mlx_;
	t_img	img_;
	t_objs	objs_;
}	t_ptrs;

/* ************************************************************************** */

//	drawing_tools

//		color_related.c
t_color	rgb_to_color(int r, int g, int b);
int		color_to_rgb(t_color color, char type);

//		put.c
void	put_pixel(t_img *img, int i, int j, t_color color);

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
void	init_mlx(t_ptrs *ptrs);
int		handle_key_press_event(int key_code, t_ptrs *ptrs);

/* ************************************************************************** */

#endif