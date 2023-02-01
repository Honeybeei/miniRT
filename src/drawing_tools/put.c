/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:59:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 12:39:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_screen(t_ptrs *ptrs, bool should_rerender)
{
	mlx_clear_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_);
	// draw_all
	if (should_rerender == true)
	{
		printf("Rerendering img...\n");
		// draw_all();
		printf("Rendering complete!!\n");
	}
	mlx_put_image_to_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, ptrs->img_.img_ptr_, 0, 0);
	print_mode_to_screen(ptrs);
}

void	put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*dst;

	dst = img->addr_ + y * img->size_line_ + x * (img->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}
