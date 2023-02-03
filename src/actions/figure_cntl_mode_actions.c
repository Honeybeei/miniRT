/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cntl_mode_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:13:20 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 23:48:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	change_figure_designation(t_objs *objs, int key_code);
static void	figure_parallel_translation(t_figure *figure, int key_code);

void	figure_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	int	i;

	i = 0;
	while (ptrs->objs_.figures_[i].is_pointed_ == false)
		i++;
	if (key_code == key_comma_ || key_code == key_full_stop_)
	{
		change_figure_designation(&ptrs->objs_, key_code);
		print_screen(ptrs, false);
	}
	else if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
	{
		figure_parallel_translation(&ptrs->objs_.figures_[i], key_code);
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

static void	figure_parallel_translation(t_figure *figure, int key_code)
{
	if (key_code == key_w_)
		figure->pos_.e[x_] += TRANSLATION_GAP_;
	else if (key_code == key_s_)
		figure->pos_.e[x_] -= TRANSLATION_GAP_;
	else if (key_code == key_d_)
		figure->pos_.e[y_] += TRANSLATION_GAP_;
	else if (key_code == key_a_)
		figure->pos_.e[y_] -= TRANSLATION_GAP_;
	else if (key_code == key_e_)
		figure->pos_.e[z_] += TRANSLATION_GAP_;
	else if (key_code == key_q_)
		figure->pos_.e[z_] -= TRANSLATION_GAP_;
}

// rotation, radius, hight should also be managed. 