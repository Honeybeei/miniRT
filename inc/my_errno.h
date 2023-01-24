/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:45:49 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 14:46:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERRNO_H
# define MY_ERRNO_H

/**
 * customized error number. It will be pared up with error_msg defined in 
 * error_management.c
 */
typedef enum e_customized_errno
{
	err_no_file_ = 0,
	err_too_much_file_,
	err_invalid_input_data_
}	t_errno;

#endif