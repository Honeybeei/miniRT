/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:42:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:29:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Same as strchr function but returns the pointer of the last occurrence
 *  of the c(2nd Parameter)
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*p_to_return;
	size_t	i;

	p_to_return = NULL;
	p = (char *)s;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == c)
			p_to_return = (p + i);
		i++;
	}
	if (p[i] == c)
		p_to_return = (p + i);
	return (p_to_return);
}

/* ************************************************************************** */