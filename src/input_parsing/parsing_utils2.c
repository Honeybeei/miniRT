/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:53:33 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 14:18:14 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static t_bool	parse_fail(char **splitted_data)
{
	int	i;

	i = 0;
	while (splitted_data[i] != NULL)
		free(splitted_data[i++]);
	return (fail_);
}

t_bool	parse_rgb(t_rgb *dst, char *rgb_data)
{
	char	**splitted_rgb;
	int		i;

	splitted_rgb = my_split(rgb_data, ',');
	i = 0;
	while (splitted_rgb[i] != NULL)
	{
		if (i > 2)
			return (parse_fail(splitted_rgb));
		if (is_valid_int_format(splitted_rgb[i]) == true)
		{
			(*dst)[i] = ft_atoi(splitted_rgb[i]);
			if (is_in_range((*dst)[i], 0, 255) == false)
				return (parse_fail(splitted_rgb));
			i++;
		}
		else
			return (parse_fail(splitted_rgb));
	}
	i = 0;
	while (splitted_rgb[i] != NULL)
		free(splitted_rgb[i++]);
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
			(*dst)[i] = my_strtod(splitted_vec[i]);
			if (is_orientation_vec == true && is_in_range((*dst)[i], 0, 1) == false)
				return (parse_fail(splitted_vec));
			i++;
		}
		else
			return (parse_fail(splitted_vec));
	}
	i = 0;
	while (splitted_vec[i] != NULL)
		free(splitted_vec[i++]);
	return (success_);
}