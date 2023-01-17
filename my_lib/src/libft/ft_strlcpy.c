/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:44:47 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:21:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Much safer function than strncpy. This function takes the full size of
 *  the destination. It copies the string from src(2nd Parameter) to dst(1st 
 * Parameter) up to destsize(3rd Parameter) and guarantee NUL-termination if 
 * there is room. NUL should be included in dstsize. The behavior is undifined 
 * when the src and dst strings overlaps.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		if (src_len + 1 <= dstsize)
			ft_memcpy(dst, src, src_len + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (src_len);
}

/* ************************************************************************** */