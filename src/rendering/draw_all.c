/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 10:31:09 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"


void	draw_all(t_mlx *mlx_, t_img *img_, t_objs *objs_)
{
	t_screen	screen_;
	t_line3		sight_;
	t_dot3		onscreen_;
//	t_color		pixel_clr;
	size_t		idx[2];

	onscreen_ = set_screen(&screen_, objs_->camera_);
	idx[y_] = 0;
	while (idx[y_] < WINDOW_HEIGHT_)
	{
		idx[x_] = 0;
		while (idx[x_] < WINDOW_WIDTH_)
		{
			sight_ = line3_by_dots(objs_->camera_.pos_, onscreen_);
			put_pixel(img_, idx[y_], idx[x_], process_pixel(objs_, sight_));
			onscreen_ = add_vec3(onscreen_, screen_.hor_unit_);
			idx[x_]++;
		}
		onscreen_ = times_vec3(screen_.ver_unit_, ++idx[y_]);
		onscreen_ = add_vec3(screen_.start_, onscreen_);
	}
	mlx_put_image_to_window(mlx_->mlx_ptr_, mlx_->win_ptr_, img_->img_ptr_, 0, 0);
}

t_dot3	set_screen(t_screen *screen_, t_camera camera_)
{
	t_vec3	v;
	double	t;

	t = WINDOW_WIDTH_ / (2 * tan(deg_to_rad(camera_.fov_ / 2)));
	screen_->center_ = add_vec3(camera_.pos_, times_vec3(camera_.dir_, t));
	if (fabs(camera_.dir_.e[y_]) == 1.0)
		v = regular_vec3(STD_X);
	else
		v = normalize_vec3(cross_product(camera_.dir_, regular_vec3(STD_Y)));
	screen_->ver_unit_ = normalize_vec3(cross_product(camera_.dir_, v));
	screen_->ver_unit_ = times_vec3(screen_->ver_unit_, SCALE_);
	screen_->hor_unit_ = times_vec3(v, SCALE_);
	v = times_vec3(screen_->ver_unit_, WINDOW_HEIGHT_ / 2);
	v = add_vec3(v, times_vec3(screen_->hor_unit_, WINDOW_WIDTH_ / 2));
	screen_->start_ = sub_vec3(screen_->center_, v);
	return (screen_->start_);
}

t_color	process_pixel(t_objs *objs_, t_line3 sight_)
{
	t_cpnt	contact_;
	
	contact_ = object_traverse(objs_, sight_);
	// 1. hit 여부, 가장 가까운 figure와 dot을 얻는다. (object_traverse를 한다)
	

	// 2. 빛을 반영한 color를 구한다.
		// 0. albedo
		// a. ambient
		// b. diffuse
		// c. specular
	// 3. shadow는 아직 잘 모르겠어.
//	ambient_process(&contact_, objs_->ambient_);
//	diffuse_process(&contact_, objs);
//	specular_process(&contact_, objs_);
//	shadow_process(&contact_, objs_);
	if (contact_.fg_)
		return (contact_.fg_->clr_); // 광 알고리즘 안들어간 임시조치입니당.
	else
		return (BACK_GROUND_COLOR_); // 이상 배경값일때의 임시조치입니당.
}
