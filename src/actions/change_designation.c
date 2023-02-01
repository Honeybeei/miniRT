/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_designation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:41:21 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 12:41:50 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"


void	change_designation(t_ptrs *ptrs, int key_code)
{
	int	i;
	if (ptrs->objs_.mode_ == mode_light_cntl_)
	{
		i = 0;
		while (ptrs->objs_.lights_[i].is_pointed_ == false)
			i++;
		if (key_code == key_comma_)
			i = (i - 1) % ptrs->objs_.light_cnt_;
		else
			i = (i + 1) % ptrs->objs_.light_cnt_;
	}
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
	{
		i = 0;
		while (ptrs->objs_.figures_[i].is_pointed_ == false)
			i++;
		if (key_code == key_comma_)
			i = (i - 1) % ptrs->objs_.figure_cnt_;
		else
			i = (i + 1) % ptrs->objs_.figure_cnt_;
	}
	else
		printf("Keycode: %03d Nothing to designate in this mode\n", key_code);
}