/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_mode_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:10:56 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/03 19:13:50 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// currently do nothing.
void	normal_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	(void)key_code;
	(void)ptrs;
	printf("Nothing designated to key [%d] in normal mode\n", key_code);
}
