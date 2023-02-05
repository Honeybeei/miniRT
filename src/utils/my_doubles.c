/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_doubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 21:34:25 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Double to number string. Max precision will be 10
 * 
 * @param n 
 * @param precision 
 * @return char* 
 */
char	*my_dtostr(double n, int precision)
{
	char	*str_arr[3];
	int		decimal;
	char	*result;

	if (precision < 0 || 10 < precision)
		return (NULL);
	if (n > INT_MAX || n < INT_MIN)
		return (NULL);
	str_arr[0] = ft_itoa((int)n);
	str_arr[1] = ".";
	decimal = (int)((fabs(n) - floor(fabs(n))) * pow(10, precision));
	str_arr[2] = ft_itoa(decimal);
	if (precision == 0)
		result = my_strarrjoin(str_arr, 1);
	else
		result = my_strarrjoin(str_arr, 3);
	free(str_arr[0]);
	free(str_arr[2]);
	return (result);
}

double	my_strtod(const char *num_str)
{
	if (check_num_str(num_str) == invalid_)
		error_management(true, err_invalid_double_, num_str, true);
	
	return (strtod(nptr, NULL));
}

t_bool	check_num_str(const char *num_str)
{
	int		i;
	t_flag	dot_flg;

	i = 0;
	dot_flg = down_;
	if (num_str == '-')
		i++;
	if (ft_isdigit(num_str[i] == 0))
		return (invalid_);
	while (num_str[i] != '\0')
	{
		if (ft_isdigit(num_str[i]) == 1)
			i++;
		else if (num_str[i] == '.' && ft_isdigit(num_str[i + 1]) == 1 && dot_flg == down_)
		{
			i++;
			dot_flg = up_;
		}
		else
			return (invalid_);
	}
	return (valid_);
}
