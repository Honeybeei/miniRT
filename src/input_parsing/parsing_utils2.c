/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:53:33 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/07 00:11:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static t_bool	parse_fail(char **splitted_data);
static t_vec3	check_and_normalize(t_vec3 vec);

static t_bool	parse_fail(char **splitted_data)
{
	int	i;

	i = 0;
	while (splitted_data[i] != NULL)
		free(splitted_data[i++]);
	free(splitted_data);
	return (fail_);
}

t_bool	parse_rgb(t_color *dst, char *rgb_data)
{
	char	**splitted_rgb;
	int		i;
	int		temp_rgb[3];

	splitted_rgb = my_split(rgb_data, ',');
	i = 0;
	while (splitted_rgb[i] != NULL)
	{
		if (i > 2)
			return (parse_fail(splitted_rgb));
		if (is_valid_int_format(splitted_rgb[i]) == true)
		{
			temp_rgb[i] = ft_atoi(splitted_rgb[i]);
			if (is_in_range(temp_rgb[i++], 0, 255) == false)
				return (parse_fail(splitted_rgb));
		}
		else
			return (parse_fail(splitted_rgb));
	}
	i = 0;
	while (splitted_rgb[i] != NULL)
		free(splitted_rgb[i++]);
	free(splitted_rgb);
	*dst = element_to_color(temp_rgb[0], temp_rgb[1], temp_rgb[2]);
	return (success_);
}

t_bool	parse_vec3(t_vec3 *dst, bool is_orientation_vec, char *vec_data)
{
	char	**splitted_vec;
	int		i;

	splitted_vec = my_split(vec_data, ',');
	i = 0;
	while (splitted_vec[i] != NULL)
	{
		if (i > 2)
			return (parse_fail(splitted_vec));
		if (is_valid_double_format(splitted_vec[i]) == true)
		{
			dst->e[i] = my_strtod(splitted_vec[i]);
			if (is_orientation_vec == true && is_in_range(dst->e[i], -1, 1) == \
			false)
				return (parse_fail(splitted_vec));
			i++;
		}
		else
			return (parse_fail(splitted_vec));
	}
	free_str_arr(splitted_vec);
	if (is_orientation_vec == true)
		*dst = check_and_normalize(*dst);
	return (success_);
}

static t_vec3	check_and_normalize(t_vec3 vec)
{
	if (vec.e[x_] == 0 && vec.e[y_] == 0 && vec.e[z_] == 0)
		error_management(true, err_invalid_input_data_, \
		"(0, 0, 0) Is not suitable for directional vector.", true);
	return (normalize_vec3(vec));
}

t_bool	is_valid_spec_cnt(char **str_arr, int expected_cnt)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
		i++;
	if (i == expected_cnt)
		return (valid_);
	return (invalid_);
}
