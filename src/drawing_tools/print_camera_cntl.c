/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera_cntl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:15:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 21:36:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_camera_cntl_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*info_arr[CAM_CNTL_MODE_STR_CNT_];

	info_arr[0] = ft_strdup("Camera");
	info_arr[1] = join_str_and_vector("View point  : ", \
	ptrs->objs_.camera_.pos_, VECTOR_PRECISION_);
	info_arr[2] = join_str_and_vector("Orientation : ", \
	ptrs->objs_.camera_.dir_, VECTOR_PRECISION_);
	info_arr[3] = join_str_and_double("FOV         : ", \
	ptrs->objs_.camera_.fov_, DOUBLE_PRECISION_);
	i = 0;
	print_spec_with_box(&ptrs->mlx_, info_arr, CAM_CNTL_MODE_STR_CNT_);
	while (i < CAM_CNTL_MODE_STR_CNT_)
		free(info_arr[i++]);
}
