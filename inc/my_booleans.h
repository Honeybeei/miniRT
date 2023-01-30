/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:44:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/30 14:46:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BOOLEANS_H
# define MY_BOOLEANS_H

//  Customized boolean to increase readability.
typedef enum e_my_boolean
{
	fail_ = 0,
	success_ = 1,
	invalid_ = 0,
	valid_ = 1
}	t_bool;

#endif