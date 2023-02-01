/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_optionals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:57:19 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 17:43:10 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	scan_sphere(t_figure *figure, char **str_arr);
static void	scan_plane(t_figure *figure, char **str_arr);
static void	scan_cylinder(t_figure *figure, char **str_arr);

void	scan_figures(t_figure *figure, char **splitted_str)
{
	if (my_strcmp(splitted_str[0], "sp") == 0)
		scan_sphere(figure, splitted_str);
	else if (my_strcmp(splitted_str[0], "pl") == 0)
		scan_plane(figure, splitted_str);
	else if (my_strcmp(splitted_str[0], "cy") == 0)
		scan_cylinder(figure, splitted_str);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid type identifier", true);
	figure->albedo = ALBEDO_;
}

static void	scan_sphere(t_figure *figure, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 4) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid sphere specific information count.", true);
	figure->type_ = type_sp_;
	if (parse_vec3(&figure->pos_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid sphere center data", true);
	if (is_valid_double_format(str_arr[2]) == true)
		figure->r_ = fabs(my_strtod(str_arr[2]) / 2);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid sphere diameter data", true);
	if (parse_rgb(&figure->clr_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid sphere color data", true);
	printf("Sphere data scan complete!!\n");
}

static void	scan_plane(t_figure *figure, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 4) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane specific information count.", true);
	figure->type_ = type_pl_;
	if (parse_vec3(&figure->pos_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane coordinate data", true);
	if (parse_vec3(&figure->dir_, true, str_arr[2]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane orientation data", true);
	if (parse_rgb(&figure->clr_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane color data", true);
	printf("Plane data scan complete!!\n");
}

static void	scan_cylinder(t_figure *figure, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 6) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder specific information count.", true);
	figure->type_ = type_cy_;
	if (parse_vec3(&figure->pos_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder coordinate data", true);
	if (parse_vec3(&figure->dir_, true, str_arr[2]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder orientation data", true);
	if (is_valid_double_format(str_arr[3]) == true)
		figure->r_ = fabs(my_strtod(str_arr[3]) / 2);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder diameter data", true);
	if (is_valid_double_format(str_arr[4]) == true)
		figure->h_ = fabs(my_strtod(str_arr[4]));
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder height data", true);
	if (parse_rgb(&figure->clr_, str_arr[5]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane color data", true);
}
