/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_cntl_mode_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:42:50 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 21:54:41 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void    light_parallel_translation(t_light *light, int key_code);
static void	change_brightness(t_light *light, int key_code);

void	light_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	int i;

	while (ptrs->objs_.lights_[i].is_pointed_ == false)
		i++;
	if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
	{
		light_parallel_translation(&ptrs->objs_.camera_[i], key_code);
		print_screen(ptrs, true);
	}
	else if (key_code == key_minus_ || key_code == key_equal_)
	{
		change_brightness(&ptrs->objs_.camera_[i], key_code);
		print_screen(ptrs, true);
	}
	else
		printf("Nothing designated to key [%d] in camera control mode\n", key_code);
}

static void    light_parallel_translation(t_light *light, int key_code)
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

static void	change_brightness(t_light *light, int key_code)
{
	if (key_code == key_minus_)
	{
		if (light->ratio_ - 0.1 > 0)
			light->ratio_ -= 0.1;
	}
	else
	{
		if (light->ratio_ + 0.1 < 1)
			light->ratio_ += 0.1;
	}
}