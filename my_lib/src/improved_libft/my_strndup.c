/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:51:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 18:16:08 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/* ************************************************************************** */

/**
 * @brief Duplicates src(param1) a given len(param2).
 * 
 * @param src 
 * @param len 
 * @return char* 
 */
char	*my_strndup(const char *src, size_t len)
{
	char	*new_str;

	new_str = my_calloc(len + 1, sizeof(char));
	ft_strlcpy(new_str, src, len + 1);
	return (new_str);
}

/* ************************************************************************** */