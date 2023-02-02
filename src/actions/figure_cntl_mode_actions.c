/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cntl_mode_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:13:20 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 21:44:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	change_figure_designation(t_objs *objs, int key_code);
static void	figure_parallel_translation(t_objs *objs, int key_code);

void	figure_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_comma_ || key_code == key_full_stop_)
	{
		change_figure_designation(&ptrs->objs_, key_code);
		print_screen(ptrs, false);
	}
	else if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
	{
		figure_parallel_translation(&ptrs->objs_, key_code);
		print_screen(ptrs, true);
	}
	else
		printf("Nothing designated to key [%d] in figure control mode\n", key_code);
}

static void	change_figure_designation(t_objs *objs, int key_code)
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

static void	figure_parallel_translation(t_objs *objs, int key_code)
{
	int	i;

	i = 0;
	while (objs->figures_[i].is_pointed_ == false)
		i++;
	if (key_code == key_w_)
		objs->figures_[i].pos_.e[x_]++;
	else if (key_code == key_s_)
		objs->figures_[i].pos_.e[x_]--;
	else if (key_code == key_d_)
		objs->figures_[i].pos_.e[y_]++;
	else if (key_code == key_a_)
		objs->figures_[i].pos_.e[y_]--;
	else if (key_code == key_e_)
		objs->figures_[i].pos_.e[z_]++;
	else if (key_code == key_q_)
		objs->figures_[i].pos_.e[z_]--;
}

// rotation, radius, hight should also be managed. 