/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:56:53 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/22 14:07:33 by seoyoo           ###   ########.fr       */
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
int		my_strcmp(const char *str1, const char *str2);
char	*my_strndup(const char *src, size_t len);

/* ************************************************************************** */

#endif