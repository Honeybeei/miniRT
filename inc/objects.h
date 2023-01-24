/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:41 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 21:29:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../minimath/inc/struct_vec3.h"

typedef struct s_ray
{
	t_pvec3	origin_;
	t_dvec3	direction_;
	t_color	color_;
}	t_ray;


#endif