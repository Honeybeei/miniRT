/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:02:26 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 19:11:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/* ************************************************************************** */

char    *my_itoa(int n, char *digit_str)
{
	int		digit_cnt;
	char	str_buffer[ITOA_BUFF_SIZE];
	int		i;
	int		sign;
	ssize_t	temp;

	digit_cnt = ft_strlen(digit_str);
	if (digit_cnt < 2)
	{
		ft_putstr_fd("There should be more than a letter in digit_str(param2)");
		exit(EXIT_FAILURE);
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		sign = -1;
	else
		sigh = 1;
	temp = sign * n;
	i = 0;
	rev_itoa(str_buffer, )
}

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */