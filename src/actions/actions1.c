/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:48 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 21:38:26 by seoyoo           ###   ########.fr       */
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
	// print mode sign
}

void	change_designation(t_ptrs *ptrs, int key_code)
{
	int	current_idx;
	if (ptrs->objs_.mode_ == mode_light_cntl_)
	{
		current_idx = 0;
		while (ptrs->objs_.lights_[current_idx].is_pointed_ == false)
			current_idx++;
		if (key_code == key_comma_)
			current_idx = (current_idx - 1) % ptrs->objs_.light_cnt_;
	}
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
	{

	}
	else
		printf("Keycode: %03d Nothing to designate in this mode\n", key_code);
}

void	parallel_translation(t_ptrs *ptrs, int key_code)
{
	int	i;

	if (ptrs->objs_.mode_ == mode_figure_cntl_)
	{
		i = 0;
		while (i < )
		{
			/* code */
		}
		// translate designated figures
	}
	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
	{
		// translate camera
	}
	else if (ptrs->objs_.mode_ == mode_light_cntl_)
	{
		// translate designated light
	}
	else
		printf("Keycode: %03d Nothing to move in this mode\n", key_code);
}