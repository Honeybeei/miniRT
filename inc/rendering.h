/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:49:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/06 16:41:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "color.h"
# include "../minimath/inc/struct_vec.h"

# define SCALE_ 0.1

// structs and define for rendering
typedef struct s_contacting_point
{
	t_dot3		pos_;
	double		tmin;
	t_bool		ismeet_;
	t_figure	*fg_;
	t_vec3		normal_;
	t_rgb		rgb_;

}	t_cpnt;
// albedo라든지...	// color라든지....	// nearest light라든지..
// ultimate environment에 대한 참조포인터라든지..

#endif