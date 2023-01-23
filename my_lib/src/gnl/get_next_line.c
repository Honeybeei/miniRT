/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:51:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/20 17:17:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_h_p_node	*head_ptr_arr = NULL;
	t_h_p_node			*head_ptr;
	char				*str;
	size_t				str_len;

	if (head_ptr_arr == NULL)
		head_ptr_arr = make_new_h_p_node(fd);
	head_ptr = search_fd_matching_head_ptr(fd, head_ptr_arr);
	if (head_ptr->head == NULL)
		head_ptr->head = make_new_b_node(head_ptr->fd);
	if (head_ptr->head == NULL)
	{
		head_ptr_arr = delete_head_ptr(head_ptr, head_ptr_arr);
		return (NULL);
	}
	str_len = count_char_till_end(head_ptr);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (termination_protocol(head_ptr));
	str[str_len] = '\0';
	copy_char_from_buffer_to_str(head_ptr, str);
	termination_protocol(head_ptr);
	return (str);
}

/*
This function returns fd matching head pointer. If there are no match, it add 
head pointing node to the end of the list and returns it. 
*/
t_h_p_node	*search_fd_matching_head_ptr(int fd, t_h_p_node *head_ptr_arr)
{
	t_h_p_node	*h_p_node;

	h_p_node = head_ptr_arr;
	while (true)
	{
		if (h_p_node->fd == fd)
			return (h_p_node);
		else if (h_p_node->next == NULL)
		{
			h_p_node->next = make_new_h_p_node(fd);
			return (h_p_node->next);
		}
		else
			h_p_node = h_p_node->next;
	}
}

/*
This function returns character count from starting point to end point. 
*/
size_t	count_char_till_end(t_h_p_node	*head_ptr)
{
	t_b_node	*b_node;
	size_t		count;

	b_node = head_ptr->head;
	count = 0;
	while (true)
	{
		if (b_node->end == -1)
		{
			count += GNL_BUFFER_SIZE - b_node->start;
			b_node->next = make_new_b_node(head_ptr->fd);
			if (b_node->next == NULL)
			{
				b_node->end = GNL_BUFFER_SIZE - 1;
				return (count);
			}
			b_node = b_node->next;
		}
		else
		{
			count += b_node->end - b_node->start + 1;
			return (count);
		}
	}
}

/*
This function copies characters from buffer to malloced string. Nul 
termination needed at the end of string.
*/
void	copy_char_from_buffer_to_str(t_h_p_node *head_ptr, char *str)
{
	t_b_node	*b_node;
	size_t		copy_size;

	b_node = head_ptr->head;
	while (b_node != NULL)
	{
		if (b_node->end == -1)
		{
			copy_size = GNL_BUFFER_SIZE - b_node->start;
			gnl_memcpy(str, b_node->buffer + b_node->start, copy_size);
			str += copy_size;
			b_node = b_node->next;
		}
		else
		{
			copy_size = b_node->end - b_node->start + 1;
			gnl_memcpy(str, b_node->buffer + b_node->start, copy_size);
			return ;
		}
	}
}

/*
This function free nodes from head to before node of tail. 
*/
void	*termination_protocol(t_h_p_node *head_ptr)
{
	t_b_node	*b_node;
	t_b_node	*del_node;

	if (head_ptr == NULL)
		return (NULL);
	b_node = head_ptr->head;
	while (b_node->next != NULL)
	{
		del_node = b_node;
		b_node = b_node->next;
		free(del_node);
	}
	if (b_node->end == b_node->read_cnt - 1)
	{
		head_ptr->head = make_new_b_node(head_ptr->fd);
		free(b_node);
	}
	else
	{
		b_node->start = b_node->end + 1;
		b_node->end = find_closest_end(b_node);
		head_ptr->head = b_node;
	}
	return (NULL);
}
