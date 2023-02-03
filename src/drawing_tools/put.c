/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:59:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 15:19:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*dst;

	dst = img->addr_ + x * img->size_line_ + y * (img->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}
