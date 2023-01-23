/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:51:34 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/20 17:17:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>  // malloc(), free()
# include <unistd.h>  // open()
# include <stdbool.h>

# define GNL_BUFFER_SIZE 10

/*
If there are no ending point at current buffer, end will be set to -1
*/
typedef struct s_buffer_node
{
	char					buffer[GNL_BUFFER_SIZE];
	ssize_t					start;
	ssize_t					end;
	ssize_t					read_cnt;
	struct s_buffer_node	*next;
}	t_b_node;

typedef struct s_head_pointer_node
{
	int							fd;
	t_b_node					*head;
	struct s_head_pointer_node	*next;
}	t_h_p_node;

// get_next_line.c
char		*get_next_line(int fd);
t_h_p_node	*search_fd_matching_head_ptr(int fd, t_h_p_node *head_ptr_arr);
size_t		count_char_till_end(t_h_p_node	*head_ptr);
void		copy_char_from_buffer_to_str(t_h_p_node *head_ptr, char *str);
void		*termination_protocol(t_h_p_node *head_ptr);

// get_next_line_utils.c
t_h_p_node	*make_new_h_p_node(int fd);
t_b_node	*make_new_b_node(int fd);
ssize_t		find_closest_end(t_b_node *buffer_node);
void		*gnl_memcpy(void *dst, const void *src, size_t n);
t_h_p_node	*delete_head_ptr(t_h_p_node *head_ptr, t_h_p_node *head_ptr_arr);

#endif