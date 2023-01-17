/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:14:47 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 11:04:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	*rev_memcpy(void *dst, const void *src, size_t n);

/* ************************************************************************** */

/**
 * @brief Same as memcpy() but this function doesn't have restrict keyword at 
 * prototype. Therefore this function should always copy in a non-destructive 
 * manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		rev_memcpy(dst, src, len);
	return (dst);
}

/* ************************************************************************** */

static void	*rev_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (dst != src)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		while (n > 0)
		{
			n--;
			temp_dst[n] = temp_src[n];
			if (n == 0)
				break ;
		}
	}
	return (dst);
}

/* ************************************************************************** */