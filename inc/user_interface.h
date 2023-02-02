/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:51 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/02 13:34:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H 

# include "defined_color.h"

# define NO_DECIMALS_		0
# define DOUBLE_PRECISION_	3
# define VECTOR_PRECISION_	3

# define INFO_STR_CNT_MAX_	5
# define INFO_STR_VER_GAP_	20

# define MODE_TEXT_LOC_X_	30
# define MODE_TEXT_LOC_Y_	30
# define MODE_TEXT_COLOR_	COLOR_WHITE_

# define INFO_TEXT_LOC_X_	WINDOW_WIDTH_ * 0.8
# define INFO_TEXT_LOC_Y_	30
# define INFO_TEXT_COLOR_	COLOR_GRAY_

typedef enum e_bracket_type
{
	bracket_type_round_ = 0,
	bracket_type_square_
}	t_bracket_type;

#endif