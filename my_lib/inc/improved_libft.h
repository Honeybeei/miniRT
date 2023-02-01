/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:56:53 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 15:14:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPROVED_LIBFT_H
# define IMPROVED_LIBFT_H

/* ************************************************************************** */

# include "libft.h"
# include <stdio.h> //  perror()

/* ************************************************************************** */

void	*my_calloc(size_t count, size_t size);
void	*my_malloc(size_t size);
char	**my_split(char const *s, char c);
char	*my_strarrjoin(char **str_arr);
int		my_strcmp(const char *str1, const char *str2);
char	*my_strndup(const char *src, size_t len);

/* ************************************************************************** */

#endif