/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:29:46 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 15:46:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// error messages pair up with t_errno. 
static char	*error_msg[] = {
	"Where is my file you idot!!!" ,
	"Its too much for me...... " ,
	"Your input data sucks"
};

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
		ft_putstr_fd(error_msg[customized_errno], STDERR_FILENO);
	if (additional_err_msg != NULL)
	{
		ft_putstr_fd(":: ", STDERR_FILENO);
		ft_putstr_fd(additional_err_msg, STDERR_FILENO);
	}
	ft_putstr_fd("\n\n", STDERR_FILENO);
	if (should_exit == true)
		exit(1);
}