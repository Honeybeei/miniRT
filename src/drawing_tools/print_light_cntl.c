/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light_cntl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:32:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 13:00:07 by seoyoo           ###   ########.fr       */
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
	print_info_with_box(&ptrs->mlx_, info_arr, LIGHT_CNTL_MODE_STR_CNT_);
	while (i < LIGHT_CNTL_MODE_STR_CNT_)
		free(info_arr[i++]);
}
