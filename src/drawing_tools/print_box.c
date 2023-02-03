/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:13:03 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 13:18:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_spec_with_box(t_mlx *mlx, char **info_str_arr, int line_cnt)
{
	int	i;
	int	j;

	j = 0;
	while (j < INFO_BOX_IN_PADDING_ * 2 + line_cnt * STR_VERTICAL_GAP_)
	{
		i = 0;
		while (i < INFO_BOX_WIDTH_)
		{
			mlx_pixel_put(mlx->mlx_ptr_, mlx->win_ptr_, INFO_BOX_LOC_X_ + i, \
			INFO_BOX_LOC_Y_ + j, INFO_BOX_COLOR_);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < line_cnt)
	{
		mlx_string_put(mlx->mlx_ptr_, mlx->win_ptr_, INFO_BOX_LOC_X_ + \
		INFO_BOX_IN_PADDING_, INFO_BOX_LOC_Y_ + INFO_BOX_IN_PADDING_ + \
		STR_VERTICAL_GAP_ * i, INFO_TEXT_COLOR_, info_str_arr[i]);
		i++;
	}
}
