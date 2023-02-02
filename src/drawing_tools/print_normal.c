/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:39:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 13:45:00 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_normal_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*temp;
	char	*info_arr[INFO_STR_CNT_MAX_];

	i = 0;
	while (ptrs->objs_.figures_[i].is_pointed_ == false)
		i++;
	info_arr[0] = ft_strdup("Press 1 ~ 5 to change mode");
	i = 0;
	while (i < 1)
	{
		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
		INFO_TEXT_LOC_X_, INFO_TEXT_LOC_Y_ + i * INFO_STR_VER_GAP_, \
		INFO_TEXT_COLOR_, info_arr[i]);
		free(info_arr[i++]);
	}
}
