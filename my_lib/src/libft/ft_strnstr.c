/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:11:05 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:29:08 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Finding a needle(2nd Parameter) in the haystack(1st Parameter) where 
 * no more then len(3rd Parameter) characters. Characters that appear after a 
 * '\0' are not searched. 
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 * 
 * 1. if needle(2nd Parameter) is empty string, haystack(1st Parameter) will be 
 * returned.
 * 2. if needle occurs in haystack, the pointer to the first character of the 
 * first occurring needle will be returned.
 * 3. NULL will be returned if there are no needle in haystack.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	need_len;
	char	*hay_p;

	hay_p = (char *)haystack;
	need_len = ft_strlen(needle);
	if (need_len == 0)
		return (hay_p);
	else
	{
		i = 0;
		while (i < len)
		{
			if (i + need_len <= len)
			{
				if (!ft_memcmp(hay_p + i, needle, need_len))
					return (hay_p + i);
			}
			else
				break ;
			i++;
		}
	}
	return (NULL);
}

/* ************************************************************************** */