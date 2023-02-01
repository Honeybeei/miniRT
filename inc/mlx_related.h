/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:16:20 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 13:45:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RELATED_H
# define MLX_RELATED_H

// window size
# define WINDOW_WIDTH_	1600
# define WINDOW_HEIGHT_	900

// mode text location 
# define MODE_TEXT_LOC_X_ 30
# define MODE_TEXT_LOC_Y_ 30

// designated light text info location 
# define LIGHT_INFO_TEXT_LOC_X_ WINDOW_WIDTH_ * 0.9
# define LIGHT_INFO_TEXT_LOC_Y_ 30

# define TEXT_COLOR_ 0xffffff  // white

// events used in this projects
enum e_x_events {
	x_key_press_ = 2,
	x_key_release_
};

// add key code here 
enum e_key_code {
	key_esc_ = 53,
	key_a_ = 0,
	key_s_ = 1,
	key_d_ = 2,
	key_q_ = 12,
	key_w_ = 13,
	key_e_ = 14,
	key_p_ = 35,
	key_1_ = 18,
	key_2_ = 19,
	key_3_ = 20,
	key_4_ = 21,
	key_5_ = 23,
	key_comma_ = 43,
	key_full_stop_ = 47,
	key_square_bracket_start_ = 33,
	key_square_bracket_end_ = 30,
	key_minus_ = 27,
	key_equal_ = 24,
	key_left_ = 123,
	key_right_ = 124,
	key_down_ = 125,
	key_up_ = 126
};

typedef struct s_mlx
{
	void	*mlx_ptr_;
	void	*win_ptr_;
}	t_mlx;

typedef struct s_image
{
	void	*img_ptr_;
	char	*addr_;
	int		bits_per_pixel_;
	int		size_line_;
	int		endian_;
}	t_img;

#endif