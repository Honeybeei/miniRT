/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:29:46 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/30 13:39:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Print error message according to customized_errno(param1). 
 * If should_exit(param2) == true, exit() function will be executed and 
 * return 1 to parent process. 
 * 
 * @param customized_errno 
 * @param should_exit 
 */
void	error_management(bool is_customized_err, t_errno customized_errno, \
		char *additional_err_msg, bool should_exit)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (is_customized_err == false)
		perror(NULL);
	else
	{
		if (customized_errno == err_no_file_)
			ft_putstr_fd("Where is my file you idot!!!", STDERR_FILENO);
		else if (customized_errno == err_too_much_file_)
			ft_putstr_fd("Its too much for me......", STDERR_FILENO);
		else if (customized_errno == err_invalid_input_data_)
			ft_putstr_fd("Your input data sucks", STDERR_FILENO);
		else if (customized_errno == err_invalid_color_type_)
			ft_putstr_fd("Invalid color type......", STDERR_FILENO);
		else
			ft_putstr_fd("Undefined error......", STDERR_FILENO);
	}
	if (additional_err_msg != NULL)
	{
		ft_putstr_fd(":: ", STDERR_FILENO);
		ft_putstr_fd(additional_err_msg, STDERR_FILENO);
	}
	ft_putstr_fd("\n\n", STDERR_FILENO);
	if (should_exit == true)
		exit(1);
}
