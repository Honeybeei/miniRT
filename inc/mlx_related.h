/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:16:20 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/19 23:19:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RELATED_H
# define MLX_RELATED_H

// window size
# define WINDOW_WIDTH_	1920
# define WINDOW_HEIGHT_	1080

// events used in this projects
enum e_x_events {
	x_key_press_ = 2,
	x_key_release_
};

// add key code here 
enum e_key_code {
	key_esc_ = 53
};

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


#endif