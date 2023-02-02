/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 13:04:15 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	*vec3_to_str(t_vec3 vec, int precision)
{
    char	*str_arr[7];
	char	*vec_str;

	str_arr[0] = "( ";
	str_arr[1] = my_dtostr(vec.e[x_], precision);
	str_arr[2] = ", ";
	str_arr[3] = my_dtostr(vec.e[y_], precision);
	str_arr[4] = ", ";
	str_arr[5] = my_dtostr(vec.e[z_], precision);
	str_arr[6] = " )";
	vec_str = my_strarrjoin(str_arr, 7);
	free(str_arr[1]);
	free(str_arr[3]);
	free(str_arr[5]);
	return (vec_str);
}

char	*join_str_and_vector(char *str, t_vec3 vec, int precision)
{
	char	*vec_str;
	char	*joined_str;

	vec_str = vec3_to_str(vec, precision);
	joined_str = ft_strjoin(str, vec_str);
	free(vec_str);
	return (joined_str);
}

char	*join_str_and_double(char *str, double n, int precision)
{
	char	*num_str;
	char	*joined_str;

	num_str = my_dtostr(n, precision);
	joined_str = ft_strjoin(str, num_str);
	free(num_str);
	return (joined_str);
}

char	*get_bracketed_int(t_bracket_type type, int n)
{
	char	*arr[3];
	char	*result;

	if (type == bracket_type_round_)
	{
		arr[0] = "( ";
		arr[2] = " )";
	}
	else
	{
		arr[0] = "[ ";
		arr[2] = " ]";
	}
	arr[1] = ft_itoa(n);
	result = my_strarrjoin(arr, 3);
	free(arr[1]);
	return (result);
}

// // hardcoded 3 is the line cnt of light information.
// void print_light_info_to_screen(t_ptrs *ptrs)
// {
// 	int		i;
// 	char	*temp_str;
// 	char	*info_arr[3];

// 	i = 0;
// 	while (ptrs->objs_.lights_[i].is_pointed_ == false)
// 		i++;
// 	temp_str = ft_itoa(i + 1);
// 	info_arr[0] = ft_strdup(ft_strjoin("Light no.", temp_str));
// 	free(temp_str);
// 	temp_str = vec3_to_str(ptrs->objs_.lights_[i].light_point_, 3);
// 	info_arr[1] = ft_strdup(ft_strjoin("Light point : ", temp_str));
// 	free(temp_str);
// 	temp_str = my_dtostr(ptrs->objs_.lights_[i].ratio_, 3);
// 	info_arr[2] = ft_strdup(ft_strjoin("Brightness  : ", temp_str));
// 	free(temp_str);
// 	i = 0;
// 	while (i < 3)
// 	{
// 		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
// 		LIGHT_INFO_TEXT_LOC_X_, LIGHT_INFO_TEXT_LOC_Y_ + i * \
// 		LIGHT_INFO_STR_PADDING_, TEXT_COLOR_, info_arr[i]);
// 		free(info_arr[i++]);
// 	}
// }

// static void print_figure_info_to_screen(t_ptrs *ptrs)
// {
// 	int		i;
// 	char	*temp_str;
// 	char	*info_arr[3];

// 	i = 0;
// 	while (ptrs->objs_.figures_[i].is_pointed_ == false)
// 		i++;
// 	temp_str = ft_itoa(i + 1);
// 	info_arr[0] = ft_strdup(ft_strjoin("Figure no.", temp_str));
// 	free(temp_str);
// 	info_arr[1] = ft_strdup(ft_strjoin("Type : ", temp_str));
// 	i = 0;
// 	while (i < 3)
// 	{
// 		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
// 		LIGHT_INFO_TEXT_LOC_X_, LIGHT_INFO_TEXT_LOC_Y_ + i * \
// 		LIGHT_INFO_STR_PADDING_, TEXT_COLOR_, info_arr[i]);
// 		free(info_arr[i++]);
// 	}
// }
