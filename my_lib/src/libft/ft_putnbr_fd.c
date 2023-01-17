/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:58:47 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 11:08:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	put_pos_num(long long num, int fd);

/* ************************************************************************** */

/**
 * @brief Prints the integer n(1st Parameter) to the given file descriptor. 
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num == 0)
		write(fd, "0", 1);
	else if (num < 0)
	{
		num *= -1;
		write(fd, "-", 1);
		put_pos_num(num, fd);
	}
	else
		put_pos_num(num, fd);
}

/* ************************************************************************** */

static void	put_pos_num(long long num, int fd)
{
	char	num_arr[20];
	int		i;

	i = 0;
	while (num > 0)
	{
		num_arr[19 - i] = num % 10 + '0';
		i++;
		num /= 10;
	}
	write(fd, &num_arr[19 - i + 1], i);
}

/* ************************************************************************** */