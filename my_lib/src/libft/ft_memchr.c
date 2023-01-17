/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:21 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 11:01:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Locates the first occurrence of c(2nd Parameter)(converted to an 
 * unsigned char) in string s(1st Parameter). 
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	temp_c;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	temp_c = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == temp_c)
			return (p + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */