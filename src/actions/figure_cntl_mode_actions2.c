/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cntl_mode_actions2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:13:20 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/08 11:27:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	figure_rotation(t_figure *figure, int key_code)
{
	if (key_code == key_left_)
		figure->dir_ = rotate_vector(figure->dir_, regular_vec3(STD_Y), \
		-FIGURE_ROTATION_DEGREE_);
	else if (key_code == key_right_)
		figure->dir_ = rotate_vector(figure->dir_, regular_vec3(STD_Y), \
		+FIGURE_ROTATION_DEGREE_);
	else if (key_code == key_up_)
		figure->dir_ = rotate_vector(figure->dir_, regular_vec3(STD_X), \
		-FIGURE_ROTATION_DEGREE_);
	else if (key_code == key_down_)
		figure->dir_ = rotate_vector(figure->dir_, regular_vec3(STD_X), \
		+FIGURE_ROTATION_DEGREE_);
}
