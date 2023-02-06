/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:56:53 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 17:08:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPROVED_LIBFT_H
# define IMPROVED_LIBFT_H

/* ************************************************************************** */

# include "libft.h"
# include <stdio.h> //  perror()

/* ************************************************************************** */

# define ITOA_BUFF_SIZE 1000

void	*my_calloc(size_t count, size_t size);
void	*my_malloc(size_t size);
char	**my_split(char const *s, char c);
char	*my_strarrjoin(char **str_arr, size_t str_cnt);
int		my_strcmp(const char *str1, const char *str2);
char	*my_strndup(const char *src, size_t len);

/* ************************************************************************** */

#endif