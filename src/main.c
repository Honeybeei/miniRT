/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 12:32:38 by seoyoo           ###   ########.fr       */
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
	parse_input(&ptrs.objs_, argv[1]);
	init_ptrs(&ptrs);
	mlx_hooks(&ptrs);
	print_screen(&ptrs, true);
	mlx_loop(ptrs.mlx_.mlx_ptr_);
	return (0);
}
