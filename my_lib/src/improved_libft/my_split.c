/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:59:27 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/22 14:07:00 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

static size_t	string_counter(char *src, char c);
static void		termination_protocol(char **str_arr, size_t i_error);
static char		**string_to_strings(char *src, char c, char **dst, size_t cnt);

/* ************************************************************************** */

/**
 * @brief Improved version(malloc NULL guarded) of ft_split.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**my_split(char const *s, char c)
{
	char	*src;
	char	**str_arr;
	size_t	str_count;

	src = (char *)s;
	str_count = string_counter(src, c);
	str_arr = my_malloc(sizeof(char *) * (str_count + 1));
	if (str_arr == NULL)
		return (NULL);
	str_arr = string_to_strings(src, c, str_arr, str_count);
	return (str_arr);
}

/* ************************************************************************** */

static size_t	string_counter(char *src, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
		{
			if (flag > 0)
			{
				count++;
				flag = 0;
			}
		}
		else
			flag++;
		i++;
	}
	if (flag > 0)
		count++;
	return (count);
}

/* ************************************************************************** */

static void	termination_protocol(char **str_arr, size_t i_error)
{
	size_t	i;

	i = 0;
	while (i < i_error)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

/* ************************************************************************** */

static char	**string_to_strings(char *src, char c, char **dst, size_t cnt)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	while (i < cnt)
	{
		str_len = 0;
		while (*src == c)
			src++;
		while (src[str_len] != c && src[str_len] != '\0')
			str_len++;
		dst[i] = my_strndup(src, str_len);
		if (dst[i] == NULL)
		{
			termination_protocol(dst, i);
			return (NULL);
		}
		src = src + str_len;
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

/* ************************************************************************** */