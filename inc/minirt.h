/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/18 12:45:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>  // for test
# include "../my_lib/inc/improved_libft.h"
# include "../mlx/mlx.h"

void	hello_world(int n);

# define WINDOW_WIDTH_
# define WINDOW_HEIGHT_

typedef struct s_mlx_pointer
{
	void	*mlx_id_;
	void	*window_;
}	t_mlx_ptr;


typedef struct s_minirt_ptrs
{
	t_mlx_ptr	mlx_;
}	t_ptrs;


#endif