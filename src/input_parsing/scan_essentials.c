/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_essentials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:42:52 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 21:38:03 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	scan_ambient_lightning(t_ambient *ambient, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 3) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid ambient lightning specific information count.", true);
	if (is_valid_double_format(str_arr[1]) == true)
		ambient->ratio_ = my_strtod(str_arr[1]);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid ambient lightning ratio data.", true);
	if (is_in_range(ambient->ratio_, 0, 1) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid ambient lightning ratio data.", true);
	if (parse_rgb(&ambient->color_, str_arr[2]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid ambient lightning color data.", true);
	ambient->increment_ = \
		times_vec3(color_to_rgb(ambient->color_), ambient->ratio_);
	printf("Ambient lightning data scan complete!!\n");
}

void	scan_camera(t_camera *camera, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 4) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid camera specific information count.", true);
	if (parse_vec3(&camera->pos_, false, str_arr[1]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid camera view point data", true);
	if (parse_vec3(&camera->dir_, true, str_arr[2]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid camera orientation vector data", true);
	if (is_valid_double_format(str_arr[3]) == true)
		camera->fov_ = my_strtod(str_arr[3]);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid camera FOV data", true);
	if (is_in_range(camera->fov_, 0.001, 179.999) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid camera FOV data out of range", true);
	printf("Camera data scan complete!!\n");
}

void	scan_light(t_light *light, char **str_arr)
{
	if (is_valid_spec_cnt(str_arr, 4) == invalid_)
		error_management(true, err_invalid_input_data_, \
		"Invalid light specific information count.", true);
	if (parse_vec3(&light->light_point_, false, str_arr[1]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid light point data", true);
	if (is_valid_double_format(str_arr[2]) == true)
		light->ratio_ = my_strtod(str_arr[2]);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid light brightness ratio data", true);
	if (is_in_range(light->ratio_, 0, 1) == false)
		error_management(true, err_invalid_input_data_, \
		"Invalid light brightness ratio data", true);
	if (parse_rgb(&light->color_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, \
		"Invalid light color data.", true);
	printf("Light data scan complete!!\n");
}
