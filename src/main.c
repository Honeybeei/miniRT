/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/08 22:03:35 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char *argv[])
{
	t_ptrs	ptrs;

	
	parse_input(&ptrs.objs_, argv[1]);
	init_ptrs(&ptrs);
	mlx_hooks(&ptrs);
	print_screen(&ptrs, true);
	mlx_loop(ptrs.mlx_.mlx_ptr_);
	return (0);
}
