/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_cntl_mode_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:46:44 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 23:56:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	camera_parallel_translation(t_camera *camera, int key_code);
static void	change_fov(t_camera *camera, int key_code);

void	camera_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
	{
		camera_parallel_translation(&ptrs->objs_.camera_, key_code);
		print_screen(ptrs, true);
	}
	else if (key_code == key_minus_ || key_code == key_equal_)
	{
		change_fov(&ptrs->objs_.camera_, key_code);
		print_screen(ptrs, true);
	}
	else
		printf("Nothing designated to key [%d] in camera control mode\n", key_code);
}

static void	camera_parallel_translation(t_camera *camera, int key_code)
{
	// should be improved. want to move 
	if (key_code == key_w_)
		camera->pos_.e[x_] += TRANSLATION_GAP_;
	else if (key_code == key_s_)
		camera->pos_.e[x_] -= TRANSLATION_GAP_;
	else if (key_code == key_d_)
		camera->pos_.e[y_] += TRANSLATION_GAP_;
	else if (key_code == key_a_)
		camera->pos_.e[y_] -= TRANSLATION_GAP_;
	else if (key_code == key_e_)
		camera->pos_.e[z_] += TRANSLATION_GAP_;
	else if (key_code == key_q_)
		camera->pos_.e[z_] -= TRANSLATION_GAP_;
}

static void	change_fov(t_camera *camera, int key_code)
{
	if (key_code == key_minus_)
	{
		if (camera->fov_ - FOV_GAP_ > FOV_MIN_)
			camera->fov_ -= FOV_GAP_;
		else
			camera->fov_ = FOV_MIN_;
	}
	else
	{
		if (camera->fov_ + FOV_GAP_ < FOV_MAX_)
			camera->fov_ += FOV_GAP_;
		else
			camera->fov_ = FOV_MAX_;
	}
}

// rotation should be added. 