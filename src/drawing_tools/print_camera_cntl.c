/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera_cntl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:15:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 17:16:15 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_camera_cntl_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*info_arr[CAM_CNTL_MODE_STR_CNT_];

	info_arr[0] = ft_strdup("Camera");
	info_arr[1] = join_str_and_vector("View point  : ", ptrs->objs_.camera_.pos_, VECTOR_PRECISION_);
	info_arr[2] = join_str_and_vector("Orientation : ", ptrs->objs_.camera_.dir_, VECTOR_PRECISION_);
	info_arr[3] = join_str_and_double("FOV         : ", ptrs->objs_.camera_.fov_, DOUBLE_PRECISION_);
	i = 0;
	while (i < CAM_CNTL_MODE_STR_CNT_)
	{
		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
		INFO_TEXT_LOC_X_, INFO_TEXT_LOC_Y_ + i * INFO_STR_VER_GAP_, \
		INFO_TEXT_COLOR_, info_arr[i]);
		free(info_arr[i++]);
	}
}