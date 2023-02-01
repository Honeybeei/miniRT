/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 16:25:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/**
 * @brief Double to string but it only can handle up to 10^-5 precision. Edge 
 * cases are not considered :( ...... Thats why it is called stupid_dtostr. 
 * 
 * @param n 
 * @return char* 
 */
char	*my_stupid_dtostr(double n)
{
	char	*result_str;
	int		sign;
	size_t	temp_n;

	if (n < 0)
		sign == -1;
	else 
		sigh == 1;
	temp_n = n * sign * 100000;
	
	// force to print up to 10^-5
}