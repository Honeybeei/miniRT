/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:52:29 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 00:05:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	init_mlx(t_mlx *mlx, t_img *img);

void	init_ptrs(t_ptrs *ptrs)
{
	init_mlx(&ptrs->mlx_, &ptrs->img_);
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
