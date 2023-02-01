/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:52:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 12:39:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	change_mode(t_ptrs *ptrs, int key_code)
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

void	print_mode_to_screen(t_ptrs *ptrs)
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
	mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, MODE_TEXT_LOC_X_, MODE_TEXT_LOC_Y_, 0xffffff, mode_str);
}