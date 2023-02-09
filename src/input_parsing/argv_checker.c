/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:57 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/09 12:12:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	check_argv(int argc, char **argv)
{
	int		argv_len;
	char	*expected_file_extension_point;

	if (argc < 2)
		error_management(true, err_no_file_, NULL, true);
	else if (argc > 2)
		error_management(true, err_too_much_file_, NULL, true);
	argv_len = ft_strlen(argv[1]);
	if (argv_len < 3)
		error_management(true, err_invalid_input_file_, NULL, true);
	expected_file_extension_point = &argv[1][argv_len - 3];
	if (my_strcmp(expected_file_extension_point, ".rt") != 0)
		error_management(true, err_invalid_input_file_, \
		"It should have \".rt\" type file extension.", true);
}
