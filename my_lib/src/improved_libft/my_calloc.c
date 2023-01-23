/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:31 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/20 17:19:41 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/* ************************************************************************** */

/**
 * @brief NULL guarded customized calloc. If exit function is able to use, it 
 * will exit when calloc fails.
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*my_calloc(size_t count, size_t size)
{
	void	*ret;
	ret = ft_calloc(count, size);
	if (ret == NULL)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

/* ************************************************************************** */