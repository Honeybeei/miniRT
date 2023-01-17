/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:17:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:32:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Get a substring from string s(1st Parameter) starts from start(2nd 
 * parameter) which is an index of the s and the maximum length of substring 
 * should be len(3rd parameter)
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	src = (char *)s;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src + start, len);
	dst[len] = '\0';
	return (dst);
}

/* ************************************************************************** */