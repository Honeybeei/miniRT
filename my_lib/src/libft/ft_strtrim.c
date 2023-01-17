/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:02:05 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 13:31:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	is_del(char c, char *del_set);
static char	*front_trimmer(char *src, char *del_set);
static char	*rear_trimmer(char *start, char *del_set);

/* ************************************************************************** */

/**
 * @brief Trim the string s1(1st Parameter). Characters from set(2nd Parameter) 
 * will be deleted from start to the end of the s1. 
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*src;
	char	*dst;
	char	*del_set;
	char	*start;
	char	*end;

	src = (char *)s1;
	del_set = (char *)set;
	start = front_trimmer(src, del_set);
	end = rear_trimmer(start, del_set);
	dst = malloc(sizeof(char) * (end - start + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, start, end - start);
	dst[end - start] = '\0';
	return (dst);
}

/* ************************************************************************** */

static int	is_del(char c, char *del_set)
{
	size_t	i;

	i = 0;
	while (del_set[i] != '\0')
	{
		if (del_set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */

static char	*front_trimmer(char *src, char *del_set)
{
	char	*start;
	size_t	i;

	i = 0;
	while (is_del(src[i], del_set) && src[i] != '\0')
		i++;
	start = src + i;
	return (start);
}

/* ************************************************************************** */

static char	*rear_trimmer(char *start, char *del_set)
{
	char	*rear;
	int		flag;

	rear = NULL;
	flag = 0;
	while (*start != '\0')
	{
		if (is_del(*start, del_set))
		{
			if (flag == 0)
			{
				rear = start;
				flag = 1;
			}
		}
		else
		{
			flag = 0;
			rear = NULL;
		}
		start++;
	}
	if (rear == NULL)
		return (start);
	return (rear);
}

/* ************************************************************************** */