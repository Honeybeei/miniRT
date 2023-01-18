/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:52:29 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/18 22:11:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_mlx(t_ptrs *ptrs)
{
	t_mlx	*mlx;

	mlx = &ptrs->mlx_;
	mlx->mlx_ptr_ = mlx_init();
	mlx->win_ptr_ = mlx_new_window(mlx->mlx_ptr_, WINDOW_WIDTH_, WINDOW_HEIGHT_, "miniRT");
	mlx_hook(mlx->win_ptr_, x_key_press_, 0, handle_key_press_event, &ptrs);
	// mlx_key_hook(mlx->win_ptr_, handle_key_press_event, ptrs);
	mlx_loop(mlx->mlx_ptr_);
}

int	handle_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_esc_)
	{
		ft_putstr_fd("Destroying window......\n", STDOUT_FILENO);
		mlx_destroy_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_);
		ft_putstr_fd("Destroying complete!\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Keycode: ", STDOUT_FILENO);
		ft_putnbr_fd(key_code, STDOUT_FILENO);
		ft_putstr_fd(" - Try another keys\n", STDOUT_FILENO);
	}
	return 0;
}