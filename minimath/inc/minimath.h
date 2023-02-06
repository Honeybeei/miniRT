/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:45:59 by jchoi             #+#    #+#             */
/*   Updated: 2023/02/06 14:07:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMATH_H
# define MINIMATH_H

# include "struct_vec.h"
# include <stdio.h>
# include <math.h>

# define ZERO 0
# define IDENTITY 1
# define STD_X 1
# define STD_Y 2
# define STD_Z 3

typedef t_vec3	t_dot3;

typedef struct s_3d_line
{
	t_dot3	pos_;
	t_vec3	dir_;
}	t_line3;

typedef struct s_3d_plane
{
	t_dot3	origin;
	t_vec3	normal;
	double	term;
}	t_plane3;

//	matrix.c
t_mtx3	init_mtx3(t_vec3 v0, t_vec3 v1, t_vec3 v2);
t_mtx3	regular_mtx3(int type);
void	print_mtx3(t_mtx3 m);

//	matrix_unary_operation.c
t_mtx3	times_mtx3(t_mtx3 m, double scalar);
t_mtx3	transpose_mtx3(t_mtx3 m);
double	det_mtx3(t_mtx3 m);
t_mtx3	inverse_mtx3(t_mtx3 m);	

//	matrix_binary_operation.c
t_mtx3	add_mtx3(t_mtx3 m1, t_mtx3 m2);
t_mtx3	add_inverse_mtx3(t_mtx3 m);
t_mtx3	sub_mtx3(t_mtx3 m1, t_mtx3 m2);
t_mtx3	mul_mtx3(t_mtx3 m1, t_mtx3 m2);
t_mtx3	pow_mtx3(t_mtx3 m, int times);

//	vector.c
t_vec3	init_vec3(double x, double y, double z);
t_vec3	regular_vec3(int type);
void	print_vec3(t_vec3 v);

//	vector_unary_operation.c
t_vec3	times_vec3(t_vec3 v, double scalar);
t_vec3	inverse_vec3(t_vec3 v);
double	sqrsum_vec3(t_vec3 v);
double	length_vec3(t_vec3 v);
t_vec3	normalize_vec3(t_vec3 v);

//	vector_binary_operation.c
t_vec3	add_vec3(t_vec3 v, t_vec3 v2);
t_vec3	sub_vec3(t_vec3 v, t_vec3 v2);
t_vec3	mul_vec3(t_vec3 v, t_vec3 v2);
double	dot_product(t_vec3 v1, t_vec3 v2);
t_vec3	cross_product(t_vec3 v1, t_vec3 v2);

//	vector_projection.c
t_vec3	tangent_vec3(t_vec3 src, t_vec3 dir);
t_vec3	normal_vec3(t_vec3 src, t_vec3 dir);

//	utils.c
double	rad_to_deg(double radian);
double	deg_to_rad(double degree);
int		positive_solution(t_vec3 co_, double *tval);

//	line.c
t_line3	init_line3(t_dot3 origin_, t_dvec3 dir_);
t_line3	line3_by_dots(t_dot3 origin_, t_dot3 dst_);

#endif
