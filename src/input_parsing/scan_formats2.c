/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_formats2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 16:58:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	scan_cylinder_format_1(t_input_cy *target, char **str_arr);
static void	scan_cylinder_format_2(t_input_cy *target, char **str_arr);

void	scan_sphere_format(t_input_sp *sphere_arr, char **str_arr)
{
	int			i;
	t_input_sp	*target;

	i = 0;
	while (sphere_arr[i].scanned_flag_ == up_)
		i++;
	target = &sphere_arr[i];
	target->scanned_flag_ = up_;
	if (is_valid_spec_cnt(str_arr, 4) == invalid_)
		error_management(true, err_invalid_input_data_, 
		"Invalid sphere specific information count.", true);
	if (parse_vec3(&target->center_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, 
		"Invalid sphere center data", true);
	if (is_valid_double_format(str_arr[2]) == true)
		target->diameter_ = my_strtod(str_arr[2]);
	else
		error_management(true, err_invalid_input_data_, 
		"Invalid sphere diameter data", true);
	if (target->diameter_ <= 0)
		error_management(true, err_invalid_input_data_, 
		"Invalid sphere diameter data", true);
	if (parse_rgb(&target->rgb_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, 
		"Invalid sphere color data", true);
	printf("Sphere[%d] data scan complete!!\n", i + 1);
}

void	scan_plane_format(t_input_pl *plane_arr, char **str_arr)
{
	int			i;
	t_input_pl	*target;

	i = 0;
	while (plane_arr[i].scanned_flag_ == up_)
		i++;
	target = &plane_arr[i];
	target->scanned_flag_ = up_;
	if (is_valid_spec_cnt(str_arr, 4) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane specific information count.", true);
	if (parse_vec3(&target->coordinate_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane coordinate data", true);
	if (parse_vec3(&target->orientation_, true, str_arr[2]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane orientation data", true);
	if (parse_rgb(&target->rgb_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane color data", true);
	printf("Plane[%d] data scan complete!!\n", i + 1);
}

void	scan_cylinder_format(t_input_cy *cylinder_arr, char **str_arr)
{
	int			i;
	t_input_cy	*target;

	i = 0;
	while (cylinder_arr[i].scanned_flag_ == up_)
		i++;
	target = &cylinder_arr[i];
	target->scanned_flag_ = up_;
	scan_cylinder_format_1(target, str_arr);
	scan_cylinder_format_2(target, str_arr);
	printf("Cylinder[%d] data scan complete!!\n", i + 1);
}

static void	scan_cylinder_format_1(t_input_cy *target, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 6) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder specific information count.", true);
	if (parse_vec3(&target->coordinate_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder coordinate data", true);
	if (parse_vec3(&target->orientation_, true, str_arr[2]) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder orientation data", true);
}

static void	scan_cylinder_format_2(t_input_cy *target, char **str_arr)
{
	if (is_valid_double_format(str_arr[3]) == true)
		target->diameter_ = my_strtod(str_arr[3]);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder diameter data", true);
	if (target->diameter_ <= 0)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder diameter data", true);
	if (is_valid_double_format(str_arr[4]) == true)
		target->height_ = my_strtod(str_arr[4]);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder height data", true);
	if (target->height_ <= 0)
		error_management(true, err_invalid_input_data_, \
		"Invalid cylinder height data", true);
	if (parse_rgb(&target->rgb_, str_arr[5]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid plane color data", true);
}