/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_cntl_mode_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:42:50 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/05 14:13:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	light_parallel_translation(t_light *light, int key_code);
static void	change_brightness(t_light *light, int key_code);
static void	change_light_designation(t_objs *objs, int key_code);

void	light_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	int	i;

	i = 0;
	while (ptrs->objs_.lights_[i].is_pointed_ == false)
		i++;
	if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
		light_parallel_translation(&ptrs->objs_.lights_[i], key_code);
	else if (key_code == key_minus_ || key_code == key_equal_)
		change_brightness(&ptrs->objs_.lights_[i], key_code);
	else if (key_code == key_comma_ || key_code == key_full_stop_)
		change_light_designation(&ptrs->objs_, key_code);
	print_screen(ptrs, false);
}

static void	light_parallel_translation(t_light *light, int key_code)
{
	if (key_code == key_w_)
		light->light_point_.e[x_] += LIGHT_TRANSLATION_GAP_;
	else if (key_code == key_s_)
		light->light_point_.e[x_] -= LIGHT_TRANSLATION_GAP_;
	else if (key_code == key_d_)
		light->light_point_.e[z_] += LIGHT_TRANSLATION_GAP_;
	else if (key_code == key_a_)
		light->light_point_.e[z_] -= LIGHT_TRANSLATION_GAP_;
	else if (key_code == key_e_)
		light->light_point_.e[y_] += LIGHT_TRANSLATION_GAP_;
	else if (key_code == key_q_)
		light->light_point_.e[y_] -= LIGHT_TRANSLATION_GAP_;
}

static void	change_brightness(t_light *light, int key_code)
{
	if (key_code == key_minus_)
	{
		if (light->ratio_ - RATIO_GAP_ > 0)
			light->ratio_ -= RATIO_GAP_;
		else
			light->ratio_ = 0;
	}
	else
	{
		if (light->ratio_ + RATIO_GAP_ < 1)
			light->ratio_ += RATIO_GAP_;
		else
			light->ratio_ = 1;
	}
}

static void	change_light_designation(t_objs *objs, int key_code)
{
	int	i;

	i = 0;
	while (objs->lights_[i].is_pointed_ == false)
		i++;
	objs->lights_[i].is_pointed_ = false;
	i += objs->light_cnt_;
	if (key_code == key_comma_)
		i = (i - 1) % objs->light_cnt_;
	else
		i = (i + 1) % objs->light_cnt_;
	objs->lights_[i].is_pointed_ = true;
	printf("Designated light [%d]\n", i + 1);
}
