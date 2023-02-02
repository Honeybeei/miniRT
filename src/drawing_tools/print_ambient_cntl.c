/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ambient_cntl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:13:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 17:25:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_ambient_light_cntl_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*info_arr[AMB_CNTL_MODE_STR_CNT_];

	info_arr[0] = ft_strdup("Ambient");
	info_arr[1] = join_str_and_double("Ambient lightning : ", ptrs->objs_.ambient_.ratio_, DOUBLE_PRECISION_);
	i = 0;
	while (i < AMB_CNTL_MODE_STR_CNT_)
	{
		// draw_info_box(line_cnt);
		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
		INFO_TEXT_LOC_X_, INFO_TEXT_LOC_Y_ + i * INFO_STR_VER_GAP_, \
		INFO_TEXT_COLOR_, info_arr[i]);
		free(info_arr[i++]);
	}
}