/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:32:57 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 20:44:48 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define ZERO 0
#define IDENTITY 1
#define STD_X 1
#define STD_Y 2
#define STD_Z 3


typedef double	t_vec3[3];
typedef	t_vec3	t_pvec3;
typedef	t_vec3	t_dvec3;

typedef t_vec3	t_mtx3[3];

typedef enum e_xyz
{
	x_ = 0,
	y_ = 1,
	z_ = 2
}	t_xyz;

//	minimath.c
void	escape();

// vector.c 
void	input_vec3(t_vec3 dst, double x, double y, double z);
void	print_vec3(t_vec3 v);
void	regular_vec3(t_vec3 v, const int type);

//	vector_unary_operation.c
double	sqrsum_vec3(t_vec3 v);
double	length_vec3(t_vec3 v);
void	add_inverse_vec3(t_vec3 dst, t_vec3 v0);
void	normalize_vec3(t_vec3 dst, t_vec3 v);

//	vector_binary_operation.c
void	times_vec3(t_vec3 dst, t_vec3 v0, const double scalar);
void	add_vec3(t_vec3 dst, t_vec3 v1, t_vec3 v2);
void	sub_vec3(t_vec3 v, t_vec3 v1, t_vec3 v2);
double	dot_product(t_vec3 v1, t_vec3 v2);
void	cross_product(t_vec3 dst, t_vec3 v1, t_vec3 v2);

//	matrix.c
void	input_mtx3(t_mtx3 dst, t_vec3 v0, t_vec3 v1 , t_vec3 v2);
void	regular_mtx3(t_mtx3 v, const int type);
void	print_mtx3(t_mtx3 m);

//	matrix_unary_operation.c
double	det_mtx3(t_mtx3 m);
void	add_inverse_mtx3(t_mtx3 dst, t_mtx3 m);
void	transpose_mtx3(t_mtx3 dst, t_mtx3 m);
void	inverse_mtx3(t_mtx3 dst, t_mtx3 m);

//	matrix_binary_operation.c
void	add_mtx3(t_mtx3 dst, t_mtx3 m1, t_mtx3 m2);
void	times_mtx3(t_mtx3 dst, t_mtx3 m, const double scalar);
void	sub_mtx3(t_mtx3 dst, t_mtx3 m1, t_mtx3 m2);
void	mul_mtx3(t_mtx3 dst, t_mtx3 m1, t_mtx3 m2);
void	pow_mtx3(t_mtx3 dst, t_mtx3 m, int times);

