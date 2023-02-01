/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:06:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 11:50:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int	handle_key_press_event(int key_code, t_ptrs *ptrs);
static void	mlx_termination_protocol(t_mlx *mlx, t_img *img);

void	mlx_hooks(t_ptrs *ptrs)
{
	mlx_key_hook(ptrs->mlx_.win_ptr_, handle_key_press_event, ptrs);
	// add mlx_something_hook to terminate mlx by pressing x at the top left frame
}

static int	handle_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_esc_)
		mlx_termination_protocol(&ptrs->mlx_, &ptrs->img_);
	else if (key_code == key_p_)
		print_inputs(&ptrs->objs_);
	else if (key_code == key_1_ || key_code == key_2_ || key_code == key_3_ || key_code == key_4_ || key_code == key_5_)
		change_mode(ptrs, key_code);
	// else if (key_code == key_comma_ || key_code == key_full_stop_)
	// 	change_designation(ptrs, key_code);  // TODO
	// else if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
	// 	parallel_translation(ptrs, key_code);  // TODO
	// else if (key_code == key_left_ || key_code == key_right_ || key_code == key_up_ || key_code == key_down_)
	// 	rotation(ptrs, key_code);  // TODO
	// else if (key_code == key_minus_ || key_code == key_equal_)
	// 	change_brightness(ptrs, key_code);  // TODO
	else
		printf("Undesignated keycode [%d]\n", key_code);
	return (0);
}

static void	mlx_termination_protocol(t_mlx *mlx, t_img *img)
{
	ft_putstr_fd("Destroying img......\n", STDOUT_FILENO);
	mlx_destroy_image(mlx->mlx_ptr_, img->img_ptr_);
	ft_putstr_fd("Destroying complete!\n", STDOUT_FILENO);
	ft_putstr_fd("Destroying window......\n", STDOUT_FILENO);
	mlx_destroy_window(mlx->mlx_ptr_, mlx->win_ptr_);
	ft_putstr_fd("Destroying complete!\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
