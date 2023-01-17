/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:26:35 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/05 21:29:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Allocate count(1st Parameter) amount with size(2nd Parameter) bytes of
 *  memory and fill with zero.
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = NULL;
	dst = (void *)malloc(count * size);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, 0, count * size);
	return (dst);
}

/* ************************************************************************** */