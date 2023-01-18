/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:52:29 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/18 12:45:40 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_minirt(t_ptrs *ptrs)
{	
	init_mlx_ptrs(&ptrs->mlx_);
}

void	init_mlx_ptrs(t_mlx_ptr *mlx_ptr)
{
	mlx_ptr->mlx_id_ = mlx_init();
	mlx_ptr->window_ = mlx_new_window(mlx_ptr->mlx_id_, WINDOW_WIDTH_, WINDOW_HEIGHT_, "miniRT");
}