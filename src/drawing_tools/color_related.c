/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:55:17 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/07 12:27:38 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	element_to_color(double r, double g, double b)
{
	int	r_;
	int	g_;
	int	b_;

	r_ = fmax(fmin(r, 0XFF), 0);
	g_ = fmax(fmin(g, 0XFF), 0);
	b_ = fmax(fmin(b, 0XFF), 0);
	return (r_ << 16 | g_ << 8 | b_);
}

t_color	rgb_to_color(t_rgb rgb)
{
	return (element_to_color(rgb.e[0], rgb.e[1], rgb.e[2]));
}

t_rgb	color_to_rgb(t_color clr)
{
	return (init_vec3((clr >> 16) & 0xFF, (clr >> 8) & 0xFF, clr & 0xFF));
}

int	color_to_element(t_color clr, char type)
{
	if (type == 'r')
		return ((clr & (0xFF << 16)) >> 16);
	else if (type == 'g')
		return ((clr & (0xFF << 8)) >> 8);
	else if (type == 'b')
		return (clr & 0xFF);
	else
		error_management(true, err_invalid_color_type_, NULL, true);
	return (-1);
}
