/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:16:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Search for c(2nd Parameter) in the string(1st Parameter). It will 
 * return a pointer of the first occurrence of the c(converted to char) , 
 * otherwise NULL will be returned if character does not appear in the string. 
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == c)
			return (p + i);
		i++;
	}
	if (p[i] == c)
		return (p + i);
	return (NULL);
}

/* ************************************************************************** */