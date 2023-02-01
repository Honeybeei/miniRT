/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_temp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:48 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 12:00:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// void	change_designation(t_ptrs *ptrs, int key_code)
// {
// 	int	i;
// 	if (ptrs->objs_.mode_ == mode_light_cntl_)
// 	{
// 		i = 0;
// 		while (ptrs->objs_.lights_[i].is_pointed_ == false)
// 			i++;
// 		if (key_code == key_comma_)
// 			i = (i - 1) % ptrs->objs_.light_cnt_;
// 		else
// 			i = (i + 1) % ptrs->objs_.light_cnt_;
// 	}
// 	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
// 	{
// 		i = 0;
// 		while (ptrs->objs_.figures_[i].is_pointed_ == false)
// 			i++;
// 		if (key_code == key_comma_)
// 			i = (i - 1) % ptrs->objs_.figure_cnt_;
// 		else
// 			i = (i + 1) % ptrs->objs_.figure_cnt_;
// 	}
// 	else
// 		printf("Keycode: %03d Nothing to designate in this mode\n", key_code);
// }

// void	parallel_translation(t_ptrs *ptrs, int key_code)
// {
// 	int	i;

// 	if (ptrs->objs_.mode_ == mode_figure_cntl_)
// 	{
// 		i = 0;
// 		while (ptrs->objs_.figures_[i].is_pointed_ == false)
// 			i++;
// 		translate_designated_figure(&ptrs->objs_.figures_[i], key_code);  // TODO
// 	}
// 	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
// 	{
// 		translate_camera(&ptrs->objs_.camera_, key_code)  // TODO
// 		// if (key_code == key_w_)
// 		// 	ptrs->objs_.camera_.pos_.e[x_]++;
// 		// else if (key_code == key_s_)
// 		// 	ptrs->objs_.camera_.pos_.e[x_]--;
// 		// else if (key_code == key_d_)
// 		// 	ptrs->objs_.camera_.pos_.e[y_]++;
// 		// else if (key_code == key_a_)
// 		// 	ptrs->objs_.camera_.pos_.e[y_]--;
// 		// else if (key_code == key_e_)
// 		// 	ptrs->objs_.camera_.pos_.e[z_]++;
// 		// else if (key_code == key_q_)
// 		// 	ptrs->objs_.camera_.pos_.e[z_]--;
// 		// translate camera
// 	}
// 	else if (ptrs->objs_.mode_ == mode_light_cntl_)
// 	{
// 		i = 0;
// 		while (ptrs->objs_.lights_[i].is_pointed_ == false)
// 			i++;
// 		translate_designated_light(&ptrs->objs_.lights_[i], key_code);
// 	}
// 	else
// 		printf("Keycode: %03d Nothing to move in this mode\n", key_code);
// }