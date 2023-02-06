/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:15:28 by jchoi             #+#    #+#             */
/*   Updated: 2023/02/06 14:06:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minimath.h"

double	rad_to_deg(double radian)
{
	return ((radian * 180.0) / M_PI);
}

double	deg_to_rad(double degree)
{
	return ((degree * M_PI) / 180.0);
}

int	positive_solution(t_vec3 co_, double *tval)
{
	double	det;
	double	val;

	det = co_.e[1] * co_.e[1] - co_.e[2] * co_.e[0] * 4;
	if (det < 0.0 || (co_.e[2] == 0.0 && co_.e[1] == 0.0))
		return (0);
	else if (co_.e[2] == 0.0)
		val = -co_.e[0] / co_.e[1];
	else
	{
		val = -(co_.e[1] + sqrt(det)) / (co_.e[2] * 2);
		if (val <= 0.0)
			val += (sqrt(det) / co_.e[2]);
	}
	if (val <= 0.0)
		return (0);
	else
	{
		*tval = val;
		return (1);
	}
}
