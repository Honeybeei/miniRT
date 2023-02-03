/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:55:17 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 14:47:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	element_to_color(double r, double g, double b)
{
	int	r_;
	int	g_;
	int	b_;

	r_ = fmin(r, 255.0);
	g_ = fmin(g, 255.0);
	b_ = fmin(b, 255.0);
	return (r_ << 16 | g_ << 8 | b_);
}

int	color_to_element(t_color clr, char type)
{
	if (type == 'r')
		return ((clr & (0xFF << 16) >> 16));
	else if (type == 'g')
		return (clr & (0xFF << 8) >> 8);
	else if (type == 'b')
		return (clr & 0xFF);
	else
		error_management(true, err_invalid_color_type_, NULL, true);
	return (-1);
}

t_color	rgb_to_color(t_rgb rgb)
{
	return (element_to_color(rgb.e[0], rgb.e[1], rgb.e[2]));
}

t_rgb	color_to_rgb(t_color clr)
{
	return (init_vec3((clr >> 16) & 0xFF, (clr >> 8) & 0xFF, clr & 0xFF));
}
