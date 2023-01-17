/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:08:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:22:52 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Applies function f(2nd Parameter) to all the characters in string 
 * s(1st Parameter).
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	dst = ft_strdup(s);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (dst[i] != '\0')
	{
		dst[i] = f(i, dst[i]);
		i++;
	}
	return (dst);
}

/* ************************************************************************** */