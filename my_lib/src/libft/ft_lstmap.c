/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:40:35 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 10:58:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Iterates the list the list 'lst'(1st Parameter) and applies the 
 * function 'f'(2nd Parameter) on the content of each node and Creates a new 
 * list resulting of the successful applications of the functions 'f'. 'del'
 * (3rd Parameter) function is used to delete the content of a node if needed.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*head_node;

	head_node = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		ft_lstadd_back(&head_node, new_node);
		lst = lst->next;
	}
	new_node = NULL;
	return (head_node);
}

/* ************************************************************************** */