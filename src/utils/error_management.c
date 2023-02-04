/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:29:46 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 01:51:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	print_customized_err(t_errno customized_errno);

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
		print_customized_err(customized_errno);
	if (additional_err_msg != NULL)
	{
		ft_putstr_fd(":: ", STDERR_FILENO);
		ft_putstr_fd(additional_err_msg, STDERR_FILENO);
	}
	ft_putstr_fd("\n\n", STDERR_FILENO);
	if (should_exit == true)
		exit(1);
}

static void	print_customized_err(t_errno customized_errno)
{
	if (customized_errno == err_no_file_)
		ft_putstr_fd("Where is my file you idot!!!", STDERR_FILENO);
	else if (customized_errno == err_too_much_file_)
		ft_putstr_fd("Its too much for me......", STDERR_FILENO);
	else if (customized_errno == err_invalid_input_data_)
		ft_putstr_fd("Your input data sucks", STDERR_FILENO);
	else if (customized_errno == err_invalid_color_type_)
		ft_putstr_fd("Invalid color type......", STDERR_FILENO);
	else if (customized_errno == err_invalid_double_)
		ft_putstr_fd("Invalid double syntax......", STDERR_FILENO);
	else
		ft_putstr_fd("Undefined error......", STDERR_FILENO);
}
