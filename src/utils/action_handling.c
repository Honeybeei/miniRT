/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:06:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 13:15:44 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int	handle_key_press_event(int key_code, t_ptrs *ptrs);

void	mlx_hooks(t_ptrs *ptrs)
{
	mlx_key_hook(ptrs->mlx_.win_ptr_, handle_key_press_event, ptrs);
}

static int	handle_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_esc_)
		mlx_termination_protocol(&ptrs->mlx_, &ptrs->img_);
	else if ((0 <= key_code && key_code <= 2) || (12 <= key_code && key_code <= 14))
	{
		parallel_translation(&ptrs->objs_, key_code);
		//  draw_all
	}
	else if (key_code == key_p_)
		print_inputs(&ptrs->objs_);
	else if (key_code == key_comma_ || key_code == key_full_stop_)
		move_highlight(ptrs, key_code);
	else
		printf("Undesignated keycode [%d]\n", key_code);
	return (0);
}

void	mlx_termination_protocol(t_mlx *mlx, t_img *img)
{
	ft_putstr_fd("Destroying img......\n", STDOUT_FILENO);
	mlx_destroy_image(mlx->mlx_ptr_, img->img_ptr_);
	ft_putstr_fd("Destroying complete!\n", STDOUT_FILENO);
	ft_putstr_fd("Destroying window......\n", STDOUT_FILENO);
	mlx_destroy_window(mlx->mlx_ptr_, mlx->win_ptr_);
	ft_putstr_fd("Destroying complete!\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

void	parallel_translation(t_objs *objs, int key_code)
{
	if (objs->figure_cnt_ == objs->highlight_)
		move_camera(objs, key_code);  // TODO
	else
		move_figure(objs, key_code);  // TODO
}

void	move_highlight(t_ptrs *ptrs, int key_code)
{
	size_t	idx_max;

	idx_max = ptrs->objs_.figure_cnt_;
	if (key_code == key_comma_)
	{
		if (ptrs->objs_.highlight_ == 0)
			ptrs->objs_.highlight_ = idx_max;
		else
			ptrs->objs_.highlight_--;
	}
	else
	{
		if (ptrs->objs_.highlight_ == idx_max)
			ptrs->objs_.highlight_ = 0;
		else
			ptrs->objs_.highlight_++;
	}
	if (ptrs->objs_.highlight_ == idx_max)
		printf("Highlight moved to camera\n");
	else
		printf("Highlight moved to figure no.%d\n", ptrs->objs_.highlight_);
	// redraw_highlight(ptrs);  // TODO
}