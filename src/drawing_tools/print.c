/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 21:57:04 by seoyoo           ###   ########.fr       */
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
	mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, MODE_TEXT_LOC_X_, \
	MODE_TEXT_LOC_Y_, TEXT_COLOR_, mode_str);
}

// hardcoded 3 is the line cnt of light information.
static void print_light_info_to_screen(t_ptrs *ptrs)
{
	int		i;
    char    *temp_str;
	char    *light_info_arr[3];

	i = 0;
	while (ptrs->objs_.lights_[i].is_pointed_ == false)
		i++;
	temp_str = ft_itoa(i + 1);
    light_info_arr[0] = ft_strdup(ft_strjoin(temp_str, " Light information"));
    free(temp_str);
	temp_str = vec3_to_str(ptrs->objs_.lights_[i].light_point_, 3);
	light_info_arr[1] = ft_strdup(ft_strjoin("Light point : ", temp_str));
	free(temp_str);
	temp_str = my_dtostr(ptrs->objs_.lights_[i].ratio_, 3);
	light_info_arr[2] = ft_strdup(ft_strjoin("Brightness  : ", temp_str));
	free(temp_str);
	i = 0;
	while (i < 3)
	{
		mlx_string_put(ptrs->mlx_.mlx_ptr_, ptrs->mlx_.win_ptr_, \
		LIGHT_INFO_TEXT_LOC_X_, LIGHT_INFO_TEXT_LOC_Y_ + i * \
		LIGHT_INFO_STR_PADDING_, TEXT_COLOR_, light_info_arr[i]);
		free(light_info_arr[i++]);
	}
}

char	*vec3_to_str(t_vec3 vec, int precision)
{
    char	*str_arr[7];
	char	*vec_str;

	str_arr[0] = "( ";
	str_arr[1] = my_dtostr(vec.e[x_], precision);
	str_arr[2] = ", ";
	str_arr[3] = my_dtostr(vec.e[y_], precision);
	str_arr[4] = ", ";
	str_arr[5] = my_dtostr(vec.e[z_], precision);
	str_arr[6] = " )";
	vec_str = my_strarrjoin(str_arr, 7);
	free(str_arr[1]);
	free(str_arr[3]);
	free(str_arr[5]);
	return (vec_str);
}