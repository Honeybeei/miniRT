/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:39:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 13:14:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_normal_mode_ui(t_ptrs *ptrs)
{
	int		i;
	char	*info_arr[NORMAL_MODE_STR_CNT_];

	i = 0;
	while (ptrs->objs_.figures_[i].is_pointed_ == false)
		i++;
	info_arr[0] = ft_strdup("Press 1 ~ 5 to change mode");
	i = 0;
	print_spec_with_box(&ptrs->mlx_, info_arr, NORMAL_MODE_STR_CNT_);
	while (i < NORMAL_MODE_STR_CNT_)
		free(info_arr[i++]);
}
