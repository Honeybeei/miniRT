/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:53:58 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:36:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	string_counter(char *src, char c);
static char		*my_strndup(char *src, size_t str_len);
static void		termination_protocol(char **str_arr, size_t i_error);
static char		**string_to_strings(char *src, char c, char **dst, size_t cnt);

/* ************************************************************************** */

/**
 * @brief Split the string s(1st Parameter) with a delimiter character del(2nd 
 * Parameter). Each splitted string will be saved in an array of strings and 
 * this array will be returned. This array also should be NULL terminated. 
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c)
{
	char	*src;
	char	**str_arr;
	size_t	str_count;

	src = (char *)s;
	str_count = string_counter(src, c);
	str_arr = malloc(sizeof(char *) * (str_count + 1));
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

static char	*my_strndup(char *src, size_t str_len)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * (str_len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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