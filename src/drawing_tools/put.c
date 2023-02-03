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

void	put_pixel(t_img *img, int i, int j, t_color color)
{
	char	*dst;

	dst = img->addr_ + i * img->size_line_ + j * (img->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}
