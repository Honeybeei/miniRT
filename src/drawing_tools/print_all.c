/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:00:12 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 21:34:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	print_mode_info_to_screen(t_ptrs *ptrs);

void	print_screen(t_ptrs *ptrs, bool should_rerender)
{
	mlx_clear_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_);
	if (should_rerender == true)
	{
		printf("Rerendering img...\n");
		draw_all(&ptrs->mlx_, &ptrs->img_, &ptrs->objs_);
		printf("Rendering complete!!\n");
	}
	mlx_put_image_to_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
	ptrs->img_.img_ptr_, 0, 0);
	print_mode_info_to_screen(ptrs);
	if (ptrs->objs_.mode_ == mode_normal_)
		print_normal_mode_ui(ptrs);
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
		print_figure_cntl_mode_ui(ptrs);
	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
		print_camera_cntl_mode_ui(ptrs);
	else if (ptrs->objs_.mode_ == mode_light_cntl_)
		print_light_cntl_mode_ui(ptrs);
	else if (ptrs->objs_.mode_ == mode_ambient_cntl_)
		print_ambient_light_cntl_mode_ui(ptrs);
}

static void	print_mode_info_to_screen(t_ptrs *ptrs)
{
	char	*mode_str;

	mode_str = NULL;
	if (ptrs->objs_.mode_ == mode_normal_)
		mode_str = "[1] Normal mode";
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
		mode_str = "[2] Figure control mode";
	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
		mode_str = "[3] Camera control mode";
	else if (ptrs->objs_.mode_ == mode_light_cntl_)
		mode_str = "[4] Light control mode";
	else if (ptrs->objs_.mode_ == mode_ambient_cntl_)
		mode_str = "[5] Ambient light control mode";
	else
		mode_str = "[?] MODE ERROR......";
	mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, MODE_TEXT_LOC_X_, \
	MODE_TEXT_LOC_Y_, MODE_TEXT_COLOR_, mode_str);
}
