/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:13:03 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 14:23:56 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_spec_with_box(t_mlx *mlx, char **info_str_arr, int line_cnt)
{
	int	i;
	int	j;
	int	box_width;
	int	box_x_loc;

	box_x_loc = WINDOW_WIDTH_ * INFO_BOX_LOC_X_RELATIVE_;
	box_width = WINDOW_WIDTH_ - box_x_loc - INFO_BOX_OUT_PADDING_;
	j = 0;
	while (j < INFO_BOX_IN_PADDING_ * 2 + line_cnt * STR_VERTICAL_GAP_)
	{
		i = 0;
		while (i < box_width)
			mlx_pixel_put(mlx->mlx_ptr_, mlx->win_ptr_, box_x_loc + i++, \
			INFO_BOX_LOC_Y_ + j, INFO_BOX_COLOR_);
		j++;
	}
	i = 0;
	while (i < line_cnt)
	{
		mlx_string_put(mlx->mlx_ptr_, mlx->win_ptr_, box_x_loc + \
		INFO_BOX_IN_PADDING_, INFO_BOX_LOC_Y_ + INFO_BOX_IN_PADDING_ + \
		STR_VERTICAL_GAP_ * i, INFO_TEXT_COLOR_, info_str_arr[i]);
		i++;
	}
}
