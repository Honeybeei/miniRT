/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/19 14:08:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ************************************************************************** */

# include <stdio.h>  // for test
# include "../my_lib/inc/improved_libft.h"
# include "../mlx/mlx.h"

# include "s_vector.h"
# include "s_figures.h"
# include "s_object.h"

/* ************************************************************************** */

# define WINDOW_WIDTH_	1920
# define WINDOW_HEIGHT_	1080

enum e_x_events {
	x_key_press_ = 2,
	x_key_release_
};

enum e_key_code {
	key_esc_ = 53
};

/* ************************************************************************** */

typedef struct s_mlx
{
	void	*mlx_ptr_;
	void	*win_ptr_;
}	t_mlx;

typedef struct s_image
{
	void	*mlx_ptr_;
	char	*addr_;
	int		bits_per_pixel_;
	int		size_line_;
	int		endian_;
}	t_img;

typedef struct s_minirt_ptrs
{
	t_mlx	mlx_;
	t_img	img_;
}	t_ptrs;

/* ************************************************************************** */

//	hello_world.c
void	hello_world(int n);

//	initialization.c
void	init_mlx(t_ptrs *ptrs);
int		handle_key_press_event(int key_code, t_ptrs *ptrs);

/* ************************************************************************** */

#endif