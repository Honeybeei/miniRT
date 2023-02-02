/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:51 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 17:34:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H 

# include "defined_color.h"

# define NO_DECIMALS_		0
# define DOUBLE_PRECISION_	3
# define VECTOR_PRECISION_	3

# define NORMAL_MODE_STR_CNT_		1
# define FIG_CNTL_MODE_STR_CNT_		6
# define CAM_CNTL_MODE_STR_CNT_		4
# define LIGHT_CNTL_MODE_STR_CNT_	3
# define AMB_CNTL_MODE_STR_CNT_		2
# define INFO_STR_VER_GAP_			20

# define MODE_TEXT_LOC_X_	30
# define MODE_TEXT_LOC_Y_	30
# define MODE_TEXT_COLOR_	COLOR_WHITE_

# define INFO_TEXT_LOC_X_	WINDOW_WIDTH_ * 0.7
# define INFO_TEXT_LOC_Y_	30
# define INFO_TEXT_COLOR_	COLOR_GRAY_

typedef enum e_bracket_type
{
	bracket_type_round_ = 0,
	bracket_type_square_
}	t_bracket_type;

#endif