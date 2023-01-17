/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:33:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 10:56:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Iterates the list 'lst'(1st Parameter) and applies the function 
 * 'f'(2nd Parameter) on the content of each node.
 * 
 * @param lst 
 * @param f 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node_p;

	node_p = lst;
	while (node_p != NULL)
	{
		f(node_p->content);
		node_p = node_p->next;
	}
}

/* ************************************************************************** */