/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_doubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 20:42:22 by seoyoo           ###   ########.fr       */
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
char *my_dtostr(double n, int precision)
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
	result = my_strarrjoin(str_arr, 3);
	free(str_arr[0]);
	free(str_arr[2]);
	return (result);
}
