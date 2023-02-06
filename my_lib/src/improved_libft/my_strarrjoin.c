/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strarrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:03:39 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 14:05:52 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/**
 * @brief Joins string array to a single string. 
 * 
 * @param str_arr 
 * @param str_cnt 
 * @return char* 
 */
char	*my_strarrjoin(char **str_arr, size_t str_cnt)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	*result_str;

	if (str_arr == NULL)
		return (NULL);
	i = 0;
	str_len = 0;
	while (i < str_cnt)
		str_len += ft_strlen(str_arr[i++]);
	result_str = my_calloc(str_len + 1, sizeof(char));
	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		str_len = ft_strlen(str_arr[i]);
		ft_memcpy(&result_str[j], str_arr[i], str_len);
		j += str_len;
		i++;
	}
	return (result_str);
}
