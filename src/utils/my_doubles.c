/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_doubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/08 16:05:14 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_bool	check_num_str(const char *num_str);
static double	handle_decimal_part(char *num_str);
static int		count_digits_for_positive_n(int n);

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
	char	*temp;

	if ((precision < 0 || 10 < precision) || (n > INT_MAX || n < INT_MIN))
		return (NULL);
	temp = ft_itoa(abs((int)n));
	if (n < 0)
		str_arr[0] = ft_strjoin("-", temp);
	else
		str_arr[0] = ft_strdup(temp);
	free(temp);
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

double	my_strtod(char *num_str)
{
	char	**str_arr;
	double	result;
	int		sign;

	if (check_num_str(num_str) == invalid_)
		error_management(true, err_invalid_double_, num_str, true);
	str_arr = my_split(num_str, '.');
	if (str_arr[1] == NULL)
		result = (double)ft_atoi(str_arr[0]);
	else
	{
		if (*str_arr[0] == '-')
			sign = -1;
		else
			sign = 1;
		result = abs(ft_atoi(str_arr[0]));
		result += handle_decimal_part(str_arr[1]);
		result *= sign;
	}
	free_str_arr(str_arr);
	return (result);
}

static t_bool	check_num_str(const char *num_str)
{
	int		i;
	t_flag	dot_flg;

	i = 0;
	dot_flg = down_;
	if (num_str[i] == '-')
		num_str++;
	while (num_str[i] != '\0')
	{
		if (num_str[i] == '.' && i > 0 && ft_isdigit(num_str[i + 1]) == true \
		&& dot_flg == down_)
		{
			dot_flg = up_;
			i++;
		}
		else if (ft_isdigit(num_str[i]) == true)
			i++;
		else
			return (invalid_);
	}
	return (valid_);
}

static double	handle_decimal_part(char *num_str)
{
	int	temp_result;

	temp_result = ft_atoi(num_str);
	return (pow(10, -count_digits_for_positive_n(temp_result)) * temp_result);
}

static int	count_digits_for_positive_n(int n)
{
	int	digit;

	digit = 0;
	while (n > 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}
