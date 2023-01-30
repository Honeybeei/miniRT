/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:51:16 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/30 13:43:44 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define INPUT_TYPE_CNT_ 6

enum e_input_type
{
	input_ambient_ = 0,
	input_camera_,
	input_light_,
	input_sphere_,
	input_plane_,
	input_cylinder
};

#endif