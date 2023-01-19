/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:35:30 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/19 17:50:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VECTOR_H
# define S_VECTOR_H

typedef struct s_3d_coordinate t_3dc;
typedef struct s_vector t_vec;

struct s_3d_coordinate
{
	double p_[3];
};

struct s_vector
{
	t_3dc	starting_point_;
	t_3dc	direction_;
	double	size_;
};

struct s_vector2
{
	t_3dc	starting_point_;
	t_3dc	ending_point_;
};


#endif