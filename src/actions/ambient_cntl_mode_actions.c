/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_cntl_mode_actions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:24:22 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 21:33:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	change_ambient_ratio(t_ambient *ambient, int key_code);

void	ambient_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	if (key_code == key_minus_ || key_code == key_equal_)
	{
		change_ambient_ratio(&ptrs->objs_.ambient_, key_code);
		print_screen(ptrs, true);
	}
	else
		printf("Nothing designated to key [%d] in ambient control mode\n", \
		key_code);
}

static void	change_ambient_ratio(t_ambient *ambient, int key_code)
{
	if (key_code == key_minus_)
	{
		if (ambient->ratio_ - RATIO_GAP_ > 0)
			ambient->ratio_ -= RATIO_GAP_;
		else
			ambient->ratio_ = 0;
	}
	else
	{
		if (ambient->ratio_ + RATIO_GAP_ < 1)
			ambient->ratio_ += RATIO_GAP_;
		else
			ambient->ratio_ = 1;
	}
}
