/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light_cntl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:32:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 18:05:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void    print_light_cntl_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*info_arr[LIGHT_CNTL_MODE_STR_CNT_];

	i = 0;
	while (ptrs->objs_.lights_[i].is_pointed_ == false)
		i++;
	info_arr[0] = join_str_and_double("Light no.", i + 1, 0);
	info_arr[1] = join_str_and_vector("Light point : ", ptrs->objs_.lights_[i].light_point_, VECTOR_PRECISION_);
    info_arr[2] = join_str_and_double("Brightness  : ", ptrs->objs_.lights_[i].ratio_, DOUBLE_PRECISION_);
	i = 0;
	while (i < LIGHT_CNTL_MODE_STR_CNT_)
	{
		// draw_info_box(line_cnt);
		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
		INFO_TEXT_LOC_X_, INFO_TEXT_LOC_Y_ + i * INFO_STR_VER_GAP_, \
		INFO_TEXT_COLOR_, info_arr[i]);
		free(info_arr[i++]);
	}
}
