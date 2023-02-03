/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:44:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 15:45:38 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BOOLEANS_H
# define MY_BOOLEANS_H

//  Customized boolean to increase readability.
typedef enum e_my_boolean
{
	false_ = 0,
	true_ = 1,
	fail_ = 0,
	success_ = 1,
	invalid_ = 0,
	valid_ = 1
}	t_bool;

#endif
