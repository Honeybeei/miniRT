/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:51 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 13:02:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H 

# include "color.h"

# define NO_DECIMALS_		0
# define DOUBLE_PRECISION_	3
# define VECTOR_PRECISION_	3

# define NORMAL_MODE_STR_CNT_		1
# define FIG_CNTL_MODE_STR_CNT_		6
# define CAM_CNTL_MODE_STR_CNT_		4
# define LIGHT_CNTL_MODE_STR_CNT_	3
# define AMB_CNTL_MODE_STR_CNT_		2
# define STR_VERTICAL_GAP_			22

# define MODE_TEXT_LOC_X_	30
# define MODE_TEXT_LOC_Y_	30
# define MODE_TEXT_COLOR_	COLOR_WHITE_

# define INFO_TEXT_LOC_X_	WINDOW_WIDTH_ * 0.7
# define INFO_TEXT_LOC_Y_	30
# define INFO_TEXT_COLOR_	COLOR_WHITE_

# define INFO_BOX_IN_PADDING_	10	
# define INFO_BOX_OUT_PADDING_	30
# define INFO_BOX_LOC_X_		WINDOW_WIDTH_ * 0.7
# define INFO_BOX_LOC_Y_		INFO_BOX_OUT_PADDING_
# define INFO_BOX_WIDTH_		WINDOW_WIDTH_ - INFO_BOX_LOC_X_ - INFO_BOX_OUT_PADDING_
# define INFO_BOX_COLOR_		COLOR_GRAY_

typedef enum e_bracket_type
{
	bracket_type_round_ = 0,
	bracket_type_square_
}	t_bracket_type;

#endif