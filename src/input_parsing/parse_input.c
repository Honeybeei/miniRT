/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:24:26 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/23 18:32:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	count_elements(t_input *input, int fd);
static void	check_element_cnt(int *obj_cnt);
static void	set_element_info(t_input *input, int fd);

void	parse_input(t_input *input, char *src)
{
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		error_management(false, 0, NULL, true);
	count_elements(input, fd);
	if (close(fd) < 0)
		error_management(false, 0, NULL, true);
	if (fd < 0)
		error_management(false, 0, NULL, true);
	check_element_cnt(input->obj_cnt_);
	set_element_info(input, fd);  // TODO
	if (close(fd) < 0)
		error_management(false, 0, NULL, true);
}

static void	count_elements(t_input *input, int fd)
{
	char	*gnl_result;
	char	*first_char_ptr;
	int		i;

	gnl_result = NULL;
	while (true)
	{
		gnl_result = get_next_line(fd);
		if (gnl_result == NULL)
			break ;
		else if (*gnl_result != '\n')
		{
			i = 0;
			while (gnl_result[i] == ' ')
				i++;
			first_char_ptr = ft_strchr(INPUT_TYPE_FIRST_CHAR_, gnl_result[i]);
			if (first_char_ptr == NULL)
				error_management(true, err_invalid_input_data_, \
				"Invalid type identifier", true);
			input->obj_cnt_[first_char_ptr - gnl_result + i]++;
		}
		free(gnl_result);
	}
	return ;
}

static void	check_element_cnt(int *obj_cnt)
{
	if (obj_cnt[type_ambient_] != 1 )
		error_management(true, err_invalid_input_data_, \
		"Ambient lightning can only be declared once", true);
	if (obj_cnt[type_camera_] != 1)
		error_management(true, err_invalid_input_data_, \
		"Camera can only be declared once", true);
	if (obj_cnt[type_light_] != 1)
		error_management(true, err_invalid_input_data_, \
		"Light can only be declared once", true);
}

static void	set_element_info(t_input *input, int fd)
{
	char	*gnl_result;

	if (input->obj_cnt_[type_sphere_] > 0)
		my_calloc(input->obj_cnt_[type_sphere_] + 1, sizeof(t_input_sp));
	if (input->obj_cnt_[type_plane_] > 0)
		my_calloc(input->obj_cnt_[type_plane_] + 1, sizeof(t_input_pl));
	if (input->obj_cnt_[type_cylinder_] > 0)
		my_calloc(input->obj_cnt_[type_cylinder_] + 1, sizeof(t_input_cy));
	while (true)
	{
		gnl_result = get_next_line(fd);
		if (gnl_result == NULL)
			break ;
		else if (*gnl_result != '\n')
			scan_single_line(input, gnl_result);
		free(gnl_result);
	}
	return ;
}
