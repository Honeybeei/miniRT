/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ambient_cntl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:13:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 21:36:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_ambient_light_cntl_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*info_arr[AMB_CNTL_MODE_STR_CNT_];

	info_arr[0] = ft_strdup("Ambient");
	info_arr[1] = join_str_and_double("Ambient lightning : ", \
	ptrs->objs_.ambient_.ratio_, DOUBLE_PRECISION_);
	i = 0;
	print_spec_with_box(&ptrs->mlx_, info_arr, AMB_CNTL_MODE_STR_CNT_);
	while (i < AMB_CNTL_MODE_STR_CNT_)
		free(info_arr[i++]);
}
