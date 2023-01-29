/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:55:17 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/29 18:12:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	rgb_to_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	color_to_rgb(t_color color, char type)
{
	if (type == 'r')
		return (color & (0xFF << 16));
	else if (type == 'g')
		return (color & (0xFF << 8));
	else if (type == 'b')
		return (color & 0xFF);
	else
		error_management(true, err_invalid_color_type_, NULL, true);
	return (-1);
}
