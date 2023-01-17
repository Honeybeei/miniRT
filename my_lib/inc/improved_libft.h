/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:56:53 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/17 01:12:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPROVED_LIBFT_H
# define IMPROVED_LIBFT_H

/* ************************************************************************** */

# include "libft.h"
# include <stdio.h> //  perror()

/* ************************************************************************** */

// EXTERNAL FUNCTION SWITCH
# define CAN_USE_EXIT_F_ true
# define CAN_USE_PERROR_F_ true

/* ************************************************************************** */

void	*my_calloc(size_t count, size_t size);
void	*my_malloc(size_t size);
int		my_strcmp(const char *str1, const char *str2);
char	*my_strndup(const char *src, size_t len);

/* ************************************************************************** */

#endif