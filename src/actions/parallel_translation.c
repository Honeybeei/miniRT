/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_translation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:38:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 19:53:15 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	translate_designated_figure(t_figure *figure, int key_code);
static void	translate_camera(t_camera *camera, int key_code);
static void	translate_designated_light(t_light *light, int key_code);

void	parallel_translation(t_ptrs *ptrs, int key_code)
{
	int	i;

	if (ptrs->objs_.mode_ == mode_figure_cntl_)
	{
		i = 0;
		while (ptrs->objs_.figures_[i].is_pointed_ == false)
			i++;
		translate_designated_figure(&ptrs->objs_.figures_[i], key_code);  // TODO
	}
	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
		translate_camera(&ptrs->objs_.camera_, key_code);
	else if (ptrs->objs_.mode_ == mode_light_cntl_)
	{
		i = 0;
		while (ptrs->objs_.lights_[i].is_pointed_ == false)
			i++;
		translate_designated_light(&ptrs->objs_.lights_[i], key_code);
	}
	else
		printf("Keycode: %03d Nothing to move in this mode\n", key_code);
	print_screen(ptrs, true);
}

static void	translate_designated_figure(t_figure *figure, int key_code)
{
	if (key_code == key_w_)
		figure->pos_.e[x_]++;
	else if (key_code == key_s_)
		figure->pos_.e[x_]--;
	else if (key_code == key_d_)
		figure->pos_.e[y_]++;
	else if (key_code == key_a_)
		figure->pos_.e[y_]--;
	else if (key_code == key_e_)
		figure->pos_.e[z_]++;
	else if (key_code == key_q_)
		figure->pos_.e[z_]--;
}

static void	translate_camera(t_camera *camera, int key_code)
{
	if (key_code == key_w_)
		camera->pos_.e[x_]++;
	else if (key_code == key_s_)
		camera->pos_.e[x_]--;
	else if (key_code == key_d_)
		camera->pos_.e[y_]++;
	else if (key_code == key_a_)
		camera->pos_.e[y_]--;
	else if (key_code == key_e_)
		camera->pos_.e[z_]++;
	else if (key_code == key_q_)
		camera->pos_.e[z_]--;
}

static void	translate_designated_light(t_light *light, int key_code)
{
	if (key_code == key_w_)
		light->light_point_.e[x_]++;
	else if (key_code == key_s_)
		light->light_point_.e[x_]--;
	else if (key_code == key_d_)
		light->light_point_.e[y_]++;
	else if (key_code == key_a_)
		light->light_point_.e[y_]--;
	else if (key_code == key_e_)
		light->light_point_.e[z_]++;
	else if (key_code == key_q_)
		light->light_point_.e[z_]--;
}