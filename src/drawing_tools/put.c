/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:59:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 01:14:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*dst;

	dst = img->addr_ + y * img->size_line_ + x * (img->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}
