/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:53:33 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/23 18:33:41 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	my_strtod(const char *nptr)
{
	// TODO : MAKE MY OWN 
	return (strtod(nptr, NULL));
}

/**
 * @brief Checks if num_str(param1) has a valid format to be a double. Only a 
 * single sign at the front and a dot will be tolerated. More than 15 digits 
 * will treated as an invalid format.
 * 
 * @param num_str 
 * @return true 
 * @return false 
 */
bool	is_valid_double_format(char *num_str)
{
	int		i;
	t_flag	dot_flag;

	if (*num_str == '-' || *num_str == '+')
		num_str++;
	i = 0;
	dot_flag = down_;
	while (num_str[i] != '\0')
	{
		if (num_str[i] == '.')
		{
			if ((i == 0 || dot_flag == up_))
				return (false);
			num_str++;
			dot_flag = up_;
		}
		if (ft_isdigit(num_str[i]) == 0)
			return (false);
		i++;
	}
	if (i > 15)
		return (false);
	return (true);
}

bool	is_valid_int_format(char *num_str)
{
	int		i;
	t_flag	minus_flag;

	if (*num_str == '-' || *num_str == '+')
	{
		if (*num_str == '-')
			minus_flag = up_;
		else
			minus_flag = down_;
		num_str++;
	}
	i = 0;
	while (num_str[i] != '\0')
	{
		if (ft_isdigit(num_str[i]) == 0)
			return (false);
		i++;
	}
	if (minus_flag == up_ && ft_strncmp("2147483648", num_str, 10) < 0)
		return (false);
	else if (minus_flag == down_ && ft_strncmp("2147483647", num_str, 10) < 0)
		return (false);
	return (true);
}

bool	is_in_range(double target, double min, double max)
{
	if (min <= target && target <= max)
		return (true);
	return (false);
}