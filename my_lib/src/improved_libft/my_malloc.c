/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:55:48 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/20 17:19:50 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/* ************************************************************************** */

/**
 * @brief NULL guarded customized malloc. If exit function is able to use, it 
 * will exit when malloc fails.
 * 
 * @param size 
 * @return void* 
 */
void	*my_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

/* ************************************************************************** */