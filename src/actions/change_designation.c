/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_designation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:41:21 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 19:28:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void change_light_designation(t_objs *objs, int key_code);
static void change_figure_designation(t_objs *objs, int key_code);

void	change_designation(t_ptrs *ptrs, int key_code)
{
	if (ptrs->objs_.mode_ == mode_light_cntl_)
		change_light_designation(&ptrs->objs_, key_code);
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
		change_figure_designation(&ptrs->objs_, key_code);
	else
		printf("Keycode: %03d Nothing to designate in this mode\n", key_code);
	print_screen(ptrs, false);
	// TODO : discuss how to highlight figure -> draw highlight directly at the window
}

static void change_light_designation(t_objs *objs, int key_code)
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

static void change_figure_designation(t_objs *objs, int key_code)
{
	int	i;

	i = 0;
	while (objs->figures_[i].is_pointed_ == false)
		i++;
	objs->figures_[i].is_pointed_ = false;
	i += objs->figure_cnt_;
	if (key_code == key_comma_)
		i = (i - 1) % objs->figure_cnt_;
	else
		i = (i + 1) % objs->figure_cnt_;
	objs->figures_[i].is_pointed_ = true;
	printf("Designated figure [%d]\n", i + 1);
}