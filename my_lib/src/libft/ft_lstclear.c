/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:35:26 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 10:55:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Delete and free the given node(1st Parameter) and every successor of 
 * that node, using 'del'(2nd Parameter) and free. Finally, the pointer to the 
 * list must be set to NULL.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_p;
	t_list	*node_del;

	node_p = *lst;
	while (node_p != NULL)
	{
		node_del = node_p;
		node_p = node_p->next;
		ft_lstdelone(node_del, del);
	}
	*lst = NULL;
}

/* ************************************************************************** */