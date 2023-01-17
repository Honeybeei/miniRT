/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:54:05 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:16:57 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Duplicates string(malloc the pointer and copy data from s1(1st 
 * Parameter)).
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(s1);
	dst = malloc(sizeof(char) * (src_len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, src_len + 1);
	return (dst);
}

/* ************************************************************************** */