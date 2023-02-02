/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:06:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 21:01:17 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int	handle_key_press_event(int key_code, t_ptrs *ptrs);
static void	mlx_termination_protocol(t_mlx *mlx, t_img *img);
static void	change_mode(t_ptrs *ptrs, int key_code);

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
	else if (ptrs->objs_.mode_ == mode_normal_)
		normal_mode_key_press_event(key_code, ptrs);
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
		figure_cntl_mode_key_press_event(key_code, ptrs);
	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
		camera_cntl_mode_key_press_event(key_code, ptrs);  // TODO
	else if (ptrs->objs_.mode_ == mode_light_cntl_)
		light_cntl_mode_key_press_event(key_code, ptrs);  // TODO
	else if (ptrs->objs_.mode_ == mode_ambient_cntl_)
		ambient_cntl_mode_key_press_event(key_code, ptrs);  // TODO
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

static void	change_mode(t_ptrs *ptrs, int key_code)
{
	if (key_code == key_1_)
		ptrs->objs_.mode_ = mode_normal_;
	else if (key_code == key_2_)
		ptrs->objs_.mode_ = mode_figure_cntl_;
	else if (key_code == key_3_)
		ptrs->objs_.mode_ = mode_camera_cntl_;
	else if (key_code == key_4_)
		ptrs->objs_.mode_ = mode_light_cntl_;
	else if (key_code == key_5_)
		ptrs->objs_.mode_ = mode_ambient_cntl_;
	printf("Entered mode %d\n", ptrs->objs_.mode_);
	print_screen(ptrs, false);
}
