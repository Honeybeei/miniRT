/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 17:27:20 by seoyoo           ###   ########.fr       */
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
