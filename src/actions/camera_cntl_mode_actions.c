/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_cntl_mode_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:46:44 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 14:10:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	camera_parallel_translation(t_camera *camera, int key_code);
static void	change_fov(t_camera *camera, int key_code);

void	camera_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
		camera_parallel_translation(&ptrs->objs_.camera_, key_code);
	else if (key_code == key_minus_ || key_code == key_equal_)
		change_fov(&ptrs->objs_.camera_, key_code);
	print_screen(ptrs, false);
}

static void	camera_parallel_translation(t_camera *camera, int key_code)
{
	t_vec3	front_ptr;
	t_vec3	right_ptr;
	t_vec3	y_axis;

	y_axis = init_vec3(0, 1, 0);
	front_ptr = times_vec3(normalize_vec3(normal_vec3(camera->dir_, y_axis)), \
	CAMERA_TRANSLATION_GAP_RATIO_);
	right_ptr = times_vec3(normalize_vec3(cross_product(camera->dir_, \
	y_axis)), CAMERA_TRANSLATION_GAP_RATIO_);
	if (key_code == key_w_)
		camera->pos_ = add_vec3(camera->pos_, front_ptr);
	else if (key_code == key_s_)
		camera->pos_ = sub_vec3(camera->pos_, front_ptr);
	else if (key_code == key_d_)
		camera->pos_ = add_vec3(camera->pos_, right_ptr);
	else if (key_code == key_a_)
		camera->pos_ = sub_vec3(camera->pos_, right_ptr);
	else if (key_code == key_e_)
		camera->pos_ = add_vec3(camera->pos_, y_axis);
	else if (key_code == key_q_)
		camera->pos_ = add_vec3(camera->pos_, y_axis);
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
