/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:53:33 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 01:45:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	if (is_orientation_vec == true)
		*dst = normalize_vec3(*dst);
	free_str_arr(splitted_vec);
	return (success_);
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

void	free_str_arr(char **str_arr)
{
	int	i;

	if (str_arr == NULL)
		return ;
	i = 0;
	while (str_arr[i] != NULL)
		free(str_arr[i++]);
	free(str_arr);
}
