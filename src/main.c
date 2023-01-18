/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/18 11:56:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(void)
{
	t_ptrs	ptrs;

	init_minirt(&ptrs);
	printf("Entered main function\n");
	hello_world(10);



	return (0);
}