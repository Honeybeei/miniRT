/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:49:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/07 16:22:11 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "color.h"
# include "../minimath/inc/struct_vec.h"

# define SCALE_ 0.1
# define KSN_ 64
# define KS_ 0.5
# define LUMEN 2

// structs and define for rendering
typedef struct s_contacting_point
{
	t_dot3		pos_;
	double		tmin;
	t_bool		ismeet_;
	t_figure	*fg_;
	t_vec3		normal_;
	t_rgb		rgb_;
	double		spclr;
	double		dffs;
	double		incrm;
	double		tval;
}	t_cpnt;
#endif
