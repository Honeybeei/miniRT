/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:41:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/08 11:43:54 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	count_elements(t_objs *objs, int fd, int input_cnt[]);
static void	plus_one_to_match(char *gnl_result, int input_cnt[]);
static void	set_elements(t_objs *objs, int fd);
static char	**get_next_line_and_split(int fd);

void	parse_input(t_objs *objs, char *src_file)
{
	int		fd;
	int		input_cnt[INPUT_TYPE_CNT_];

	fd = open(src_file, O_RDONLY);
	if (fd < 0)
		error_management(false, 0, NULL, true);
	count_elements(objs, fd, input_cnt);
	if (close(fd) < 0)
		error_management(false, 0, NULL, true);
	fd = open(src_file, O_RDONLY);
	if (fd < 0)
		error_management(false, 0, NULL, true);
	set_elements(objs, fd);
	if (close(fd) < 0)
		error_management(false, 0, NULL, true);
}

static void	count_elements(t_objs *objs, int fd, int input_cnt[])
{
	char	*gnl_result;

	ft_bzero(input_cnt, sizeof(int) * INPUT_TYPE_CNT_);
	while (true)
	{
		gnl_result = get_next_line(fd);
		if (gnl_result == NULL)
			break ;
		else if (*gnl_result != '\n')
			plus_one_to_match(gnl_result, input_cnt);
		free(gnl_result);
	}
	if (input_cnt[input_ambient_] != 1)
		error_management(true, err_invalid_input_data_, \
		"Invalid ambient light element count", true);
	if (input_cnt[input_camera_] != 1)
		error_management(true, err_invalid_input_data_, \
		"Invalid camera element count", true);
	if (IS_MANDATORY_ == true && input_cnt[input_light_] != 1)
		error_management(true, err_invalid_input_data_, \
		"Only a single light needed in mandatory", true);
	objs->light_cnt_ = input_cnt[input_light_];
	objs->figure_cnt_ = input_cnt[input_sphere_] + input_cnt[input_plane_] + \
	input_cnt[input_cylinder];
	return ;
}

static void	plus_one_to_match(char *gnl_result, int input_cnt[])
{
	if (ft_strncmp(gnl_result, "A ", 2) == 0)
		input_cnt[input_ambient_]++;
	else if (ft_strncmp(gnl_result, "C ", 2) == 0)
		input_cnt[input_camera_]++;
	else if (ft_strncmp(gnl_result, "L ", 2) == 0)
		input_cnt[input_light_]++;
	else if (ft_strncmp(gnl_result, "sp ", 3) == 0)
		input_cnt[input_sphere_]++;
	else if (ft_strncmp(gnl_result, "pl ", 3) == 0)
		input_cnt[input_plane_]++;
	else if (ft_strncmp(gnl_result, "cy ", 3) == 0)
		input_cnt[input_cylinder]++;
	else
		error_management(true, err_invalid_input_data_, \
		"Invalid type identifier", true);
}

static void	set_elements(t_objs *objs, int fd)
{
	char	**splitted_str;
	int		idx[2];

	objs->lights_ = my_calloc(objs->light_cnt_, sizeof(t_light));
	objs->figures_ = my_calloc(objs->figure_cnt_, sizeof(t_figure));
	ft_bzero(idx, sizeof(int) * 2);
	while (true)
	{
		splitted_str = get_next_line_and_split(fd);
		if (splitted_str == NULL)
			break ;
		else if (my_strcmp(splitted_str[0], "A") == 0)
			scan_ambient_lightning(&objs->ambient_, splitted_str);
		else if (my_strcmp(splitted_str[0], "C") == 0)
			scan_camera(&objs->camera_, splitted_str);
		else if (my_strcmp(splitted_str[0], "L") == 0)
			scan_light(&objs->lights_[idx[0]++], splitted_str);
		else
			scan_figures(&objs->figures_[idx[1]++], splitted_str);
		free_str_arr(splitted_str);
	}
}

static char	**get_next_line_and_split(int fd)
{
	char	*gnl_result;
	char	**splitted_str;

	while (true)
	{
		gnl_result = get_next_line_without_new_line(fd);
		if (gnl_result == NULL)
			return (NULL);
		else if (*gnl_result == '\0')
			free(gnl_result);
		else
			break ;
	}
	splitted_str = my_split(gnl_result, ' ');
	free(gnl_result);
	return (splitted_str);
}
