/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/25 18:01:14 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char *argv[])
{
	t_ptrs	ptrs;

	if (argc < 2)
		error_management(true, err_no_file_, NULL, true);
	else if (argc > 2)
		error_management(true, err_too_much_file_, NULL, true);
	init_ptrs(&ptrs);
	parse_input(&ptrs.input_, argv[1]);
	test_print_inputs(&ptrs.input_);
	// input_transformation(&ptrs);  // TODO
	init_mlx(&ptrs);
	mlx_loop(ptrs.mlx_.mlx_ptr_);
	return (0);
}