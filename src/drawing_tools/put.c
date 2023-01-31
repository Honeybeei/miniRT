/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:59:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 21:50:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	put_pixel(t_img *img, int i, int j, t_color color)
{
	char	*dst;

	dst = img->addr_ + i * img->size_line_ + j * (img->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}

void	put_circle(t_img *img, t_vec2 center, double rad, t_color color)
{
	double	x;
	double	y;
	double	d;

	y = 0;
	while (y < WINDOW_HEIGHT_)
	{
		x = 0;
		while (x < WINDOW_WIDTH_)
		{
			d = sqrt(pow((center.e[x_] - x), 2) + pow((center.e[y_] - y), 2));
			if (rad > d)
				put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
