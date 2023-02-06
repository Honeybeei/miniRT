/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:52:29 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 16:48:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	init_mlx(t_mlx *mlx, t_img *img);
static void	init_objs(t_objs *objs);

void	init_ptrs(t_ptrs *ptrs)
{
	init_mlx(&ptrs->mlx_, &ptrs->img_);
	init_objs(&ptrs->objs_);
}

static void	init_mlx(t_mlx *mlx, t_img *img)
{
	mlx->mlx_ptr_ = mlx_init();
	mlx->win_ptr_ = mlx_new_window(mlx->mlx_ptr_, WINDOW_WIDTH_, \
	WINDOW_HEIGHT_, "miniRT");
	img->img_ptr_ = mlx_new_image(mlx->mlx_ptr_, WINDOW_WIDTH_, WINDOW_HEIGHT_);
	img->addr_ = mlx_get_data_addr(img->img_ptr_, &img->bits_per_pixel_, \
	&img->size_line_, &img->endian_);
}

static void	init_objs(t_objs *objs)
{
	size_t	i;

	objs->mode_ = mode_normal_;
	i = 0;
	while (i < objs->light_cnt_)
		objs->lights_[i++].is_pointed_ = false;
	if (objs->light_cnt_ > 0)
		objs->lights_[0].is_pointed_ = true;
	i = 0;
	while (i < objs->figure_cnt_)
	{
		objs->figures_[i].is_pointed_ = false;
		if (objs->figures_[i].type_ == type_pl_)
			objs->figures_[i].obj_ = my_calloc(1, sizeof(t_pl));
		else if (objs->figures_[i].type_ == type_sp_)
			objs->figures_[i].obj_ = my_calloc(1, sizeof(t_sp));
		else if (objs->figures_[i].type_ == type_cy_)
			objs->figures_[i].obj_ = my_calloc(1, sizeof(t_cy));
		i++;
	}
	if (objs->figure_cnt_ > 0)
		objs->figures_[0].is_pointed_ = true;
}
