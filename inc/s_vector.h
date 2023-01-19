/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:35:30 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/19 19:38:34 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VECTOR_H
# define S_VECTOR_H

enum e_xyz {
	x_ = 0,
	y_,
	z_
};

typedef struct s_vector_3d
{
	double	vec_[3];
	// double	x_;
	// double	y_;
	// double	z_;
}	t_vec3;

typedef t_vec3 position_v_;
typedef t_vec3 direction_v_;

typedef struct s_ray
{
	position_v_		p_;
	direction_v_	d_;
	double			scalar_;
	int				etc_;
};

#endif