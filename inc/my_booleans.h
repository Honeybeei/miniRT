/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:44:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 14:45:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BOOLEANS_H
# define MY_BOOLEANS_H

//  Customized boolean to increase readability.
typedef enum e_my_boolean
{
	fail_ = 0,
	success_,
	invalid_ = 0,
	valid_
}	t_bool;

#endif