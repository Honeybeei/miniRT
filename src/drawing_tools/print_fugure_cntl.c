/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fugure_cntl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:25:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 18:05:46 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int set_plane_info_to_print(t_figure *figure, char **info_arr);
static int set_sphere_info_to_print(t_figure *figure, char **info_arr);
static int set_cylinder_info_to_print(t_figure *figure, char **info_arr);

void	print_figure_cntl_mode_ui(t_ptrs *ptrs)
{
	int		i;
	int		line_cnt;
	char	*info_arr[FIG_CNTL_MODE_STR_CNT_];

	i = 0;
	while (ptrs->objs_.figures_[i].is_pointed_ == false)
		i++;
	info_arr[0] = join_str_and_double("Figure no.", i + 1, 0);
	if (ptrs->objs_.figures_[i].type_ == type_pl_)
		line_cnt = set_plane_info_to_print(&ptrs->objs_.figures_[i], info_arr);
	else if (ptrs->objs_.figures_[i].type_ == type_sp_)
		line_cnt = set_sphere_info_to_print(&ptrs->objs_.figures_[i], info_arr);
	else
		line_cnt = set_cylinder_info_to_print(&ptrs->objs_.figures_[i], info_arr);
	i = 0;
	while (i < line_cnt)
	{
		// draw_info_box(line_cnt);
		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
		INFO_TEXT_LOC_X_, INFO_TEXT_LOC_Y_ + i * INFO_STR_VER_GAP_, \
		INFO_TEXT_COLOR_, info_arr[i]);
		free(info_arr[i++]);
	}
}

static int set_plane_info_to_print(t_figure *figure, char **info_arr)
{
	info_arr[1] = ft_strdup("Type        : plane");
	info_arr[2] = join_str_and_vector("Coordinates : ", figure->pos_, VECTOR_PRECISION_);
	info_arr[3] = join_str_and_vector("Orientation : ", figure->dir_, VECTOR_PRECISION_);
	return (4);
}

static int set_sphere_info_to_print(t_figure *figure, char **info_arr)
{
	info_arr[1] = ft_strdup("Type   : sphere");
	info_arr[2] = join_str_and_vector("Center : ", figure->pos_, VECTOR_PRECISION_);
	info_arr[3] = join_str_and_double("Radius : ", figure->r_, DOUBLE_PRECISION_);
	return (4);
}

static int set_cylinder_info_to_print(t_figure *figure, char **info_arr)
{
	info_arr[1] = ft_strdup("Type        : cylinder");
	info_arr[2] = join_str_and_vector("Center      : ", figure->pos_, VECTOR_PRECISION_);
	info_arr[3] = join_str_and_vector("Orientation : ", figure->dir_, VECTOR_PRECISION_);
	info_arr[4] = join_str_and_double("Radius      : ", figure->r_, DOUBLE_PRECISION_);
	info_arr[5] = join_str_and_double("Height      : ", figure->h_, DOUBLE_PRECISION_);
	return (6);
}

