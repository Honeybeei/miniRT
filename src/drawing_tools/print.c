/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 15:29:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	print_mode_to_screen(t_ptrs *ptrs);
static void print_light_info_to_screen(t_ptrs *ptrs);

void	print_screen(t_ptrs *ptrs, bool should_rerender)
{
	mlx_clear_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_);
	if (should_rerender == true)
	{
		printf("Rerendering img...\n");
		// draw_all();
		printf("Rendering complete!!\n");
	}
	mlx_put_image_to_window(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, ptrs->img_.img_ptr_, 0, 0);
	print_mode_to_screen(ptrs);
	if (ptrs->objs_.mode_ == mode_light_cntl_)
		print_light_info_to_screen(ptrs);
}

static void	print_mode_to_screen(t_ptrs *ptrs)
{
	char	*mode_str;

	mode_str = NULL;
	if (ptrs->objs_.mode_ == mode_normal_)
		mode_str = "[1] Normal mode";
	else if (ptrs->objs_.mode_ == mode_figure_cntl_)
		mode_str = "[2] Figure control mode";
	else if (ptrs->objs_.mode_ == mode_camera_cntl_)
		mode_str = "[3] Camera control mode";
	else if (ptrs->objs_.mode_ == mode_light_cntl_)
		mode_str = "[4] Light control mode";
	else if (ptrs->objs_.mode_ == mode_ambient_cntl_)
		mode_str = "[5] Ambient light control mode";
	else
		mode_str = "[?] MODE ERROR......";
	mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, MODE_TEXT_LOC_X_, MODE_TEXT_LOC_Y_, TEXT_COLOR_, mode_str);
}

// hardcoded 5 is the line cnt of light information.
static void print_light_info_to_screen(t_ptrs *ptrs)
{
	int		i;
    char    *temp_str;
	char    **light_info_arr;

    light_info_arr = my_calloc(5, sizeof(char *));
	i = 0;
	while (ptrs->objs_.lights_[i].is_pointed_ == false)
		i++;
	temp_str = ft_itoa(i + 1);
    light_info_arr[0] = ft_strdup(ft_strjoin(temp_str, " Light information\n"));
    free(temp_str);

	mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, LIGHT_INFO_TEXT_LOC_X_, LIGHT_INFO_TEXT_LOC_Y_, TEXT_COLOR_, light_info_str);
	free(light_info_str);
    // MUST FREE ALL
}

char    *vec3_to_str(t_vec3 vec)
{
    
}