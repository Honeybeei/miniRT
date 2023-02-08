/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:57 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/08 22:03:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

check_argv(int argc, char **argv)
{
	int	argv_len;

	if (argc < 2)
		error_management(true, err_no_file_, NULL, true);
	else if (argc > 2)
		error_management(true, err_too_much_file_, NULL, true);
	argv_len = ft_strlen(argv[1]);
	if (argv_len < 3)
		error_management(true, err_invalid_input_file_, NULL, true);
	ft_memcmp(argv[1])
}
