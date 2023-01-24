/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_formats1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 15:14:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	scan_single_line(t_input *input, char *input_str)
{
	char	**str_arr;
	int		i;

	str_arr = my_split(input_str, ' ');
	if (my_strcmp(str_arr[0], "A") == 0)
		scan_ambient_format(&input->ambient_, str_arr);
	else if (my_strcmp(str_arr[0], "C") == 0)
		scan_camera_format(&input->camera_, str_arr);
	else if (my_strcmp(str_arr[0], "L") == 0)
		scan_light_format(&input->light_, str_arr);
	else if (my_strcmp(str_arr[0], "sp") == 0)
		scan_sphere_format(input->sphere_, str_arr);
	else if (my_strcmp(str_arr[0], "pl") == 0)
		scan_plane_format(input->plane_, str_arr);
	else if (my_strcmp(str_arr[0], "cy") == 0)
		scan_cylinder_format(input->cylinder_, str_arr);
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid type identifier", true);
	i = 0;
	while (str_arr[i] != NULL)
		free(str_arr[i++]);
}

void	scan_ambient_format(t_input_a *ambient, char **str_arr)
{	
	if (is_valid_double_format(str_arr[1]) == true)
		ambient->ratio_ = my_strtod(str_arr[1]);
	else
		error_management(true, err_invalid_input_data_, "Invalid ambient lightning ratio data.", true);
	if (is_in_range(ambient->ratio_, 0, 1) == false)
		error_management(true, err_invalid_input_data_, "Invalid ambient lightning ratio data.", true);
	if (parse_rgb(&ambient->rgb_, str_arr[2]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid ambient lightning color data.", true);
	printf("Ambient lightning data scan complete!!\n");
}

void	scan_camera_format(t_input_c *camera, char **str_arr)
{	
	if (parse_vec3(&camera->view_point_, false, str_arr[1]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid camera view point data", true);
	if (parse_vec3(&camera->orientation_, true, str_arr[2]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid camera orientation vector data", true);
	if (is_valid_double_format(str_arr[3]) == true)
		camera->fov_ = my_strtod(str_arr[3]);
	else
		error_management(true, err_invalid_input_data_, "Invalid camera FOV data", true);
	if (is_in_range(camera->fov_, 0, 180) == false)
		error_management(true, err_invalid_input_data_, "Invalid camera FOV data", true);
	printf("Camera data scan complete!!\n");
}

void	scan_light_format(t_input_l *light, char **str_arr)
{
	if (parse_vec3(&light->light_point_, false, str_arr[1]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid light point data", true);
	if (is_valid_double_format(str_arr[2]) == true)
		light->ratio_ = my_strtod(str_arr[2]);
	else
		error_management(true, err_invalid_input_data_, "Invalid light brightness ratio data", true);
	if (is_in_range(light->ratio_, 0, 1) == false)
		error_management(true, err_invalid_input_data_, "Invalid light brightness ratio data", true);
	printf("Light data scan complete!!\n");
}

void	scan_sphere_format(t_input_sp *sphere_arr, char **str_arr)
{
	int			i;
	t_input_sp	*target;

	i = 0;
	while (sphere_arr[i].scanned_flag_ == up_)
		i++;
	target = &sphere_arr[i];
	target->scanned_flag_ = up_;
	if (parse_vec3(&target->center_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, "Invalid sphere center data", true);
	if (is_valid_double_format(str_arr[2]) == true)
		target->diameter_ = my_strtod(str_arr[2]);
	else
		error_management(true, err_invalid_input_data_, "Invalid sphere diameter data", true);
	if (target->diameter_ <= 0)
		error_management(true, err_invalid_input_data_, "Invalid sphere diameter data", true);
	if (parse_rgb(&target->rgb_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid sphere color data", true);
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
	if (parse_vec3(&target->coordinate_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, "Invalid plane coordinate data", true);
	if (parse_vec3(&target->orientation_, true, str_arr[2]) == false)
		error_management(true, err_invalid_input_data_, "Invalid plane orientation data", true);
	if (parse_rgb(&target->rgb_, str_arr[3]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid plane color data", true);
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
	if (parse_vec3(&target->coordinate_, false, str_arr[1]) == false)
		error_management(true, err_invalid_input_data_, "Invalid cylinder coordinate data", true);
	if (parse_vec3(&target->orientation_, true, str_arr[2]) == false)
		error_management(true, err_invalid_input_data_, "Invalid cylinder orientation data", true);
	if (is_valid_double_format(str_arr[3]) == true)
		target->diameter_ = my_strtod(str_arr[3]);
	else
		error_management(true, err_invalid_input_data_, "Invalid cylinder diameter data", true);
	if (target->diameter_ <= 0)
		error_management(true, err_invalid_input_data_, "Invalid cylinder diameter data", true);
	if (is_valid_double_format(str_arr[4]) == true)
		target->height_ = my_strtod(str_arr[4]);
	else
		error_management(true, err_invalid_input_data_, "Invalid cylinder height data", true);
	if (target->height_ <= 0)
		error_management(true, err_invalid_input_data_, "Invalid cylinder height data", true);
	if (parse_rgb(&target->rgb_, str_arr[5]) == fail_)
		error_management(true, err_invalid_input_data_, "Invalid plane color data", true);
	printf("Cylinder[%d] data scan complete!!\n", i + 1);
}

