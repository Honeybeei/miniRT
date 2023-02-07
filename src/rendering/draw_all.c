/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/07 20:20:38 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	draw_all(t_mlx *mlx_, t_img *img_, t_objs *objs_)
{
	t_screen	screen_;
	t_line3		sight_;
	t_dot3		onscreen_;
	size_t		i[2];

	onscreen_ = set_screen(&screen_, objs_->camera_);
	i[y_] = 0;
	while (i[y_] < WINDOW_HEIGHT_)
	{
		i[x_] = 0;
		while (i[x_] < WINDOW_WIDTH_)
		{
			sight_ = line3_by_dots(objs_->camera_.pos_, onscreen_);
			put_pixel(img_, i[y_], i[x_], process_pixel(objs_, sight_, i[y_]));
			onscreen_ = add_vec3(onscreen_, screen_.hor_unit_);
			i[x_]++;
		}
		onscreen_ = times_vec3(screen_.ver_unit_, ++i[y_]);
		onscreen_ = add_vec3(screen_.start_, onscreen_);
	}
	mlx_put_image_to_window(mlx_->mlx_ptr_,
		mlx_->win_ptr_, img_->img_ptr_, 0, 0);
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

t_color	process_pixel(t_objs *objs_, t_line3 sight_, size_t y)
{
	t_cpnt	contact_;
	t_rgb	delta_;
	size_t	i;
	double	tval;

	if (object_traverse(objs_, sight_, &contact_))
	{
		contact_.rgb_ = regular_vec3(ZERO);
		contact_.normal_ = get_normal(contact_.pos_, sight_, contact_.fg_);
		i = 0;
		while (i < objs_->light_cnt_)
			get_light(objs_, i++, sight_, &contact_);
		delta_ = add_vec3(contact_.rgb_, objs_->ambient_.increment_);
		delta_ = times_vec3(delta_, 1.0 / 256);
		contact_.rgb_ = mul_vec3(delta_, color_to_rgb(contact_.fg_->clr_));
		return (rgb_to_color(contact_.rgb_));
	}
	else
	{
		tval = ((double)y / WINDOW_HEIGHT_);
		return (rgb_to_color(times_vec3(add_vec3(times_vec3(init_vec3(1, 1, 1), 1 - tval), times_vec3(init_vec3(0.5, 0.7, 1.0), tval)), 256)));
	}
}

t_bool	object_traverse(t_objs *objs_, t_line3 sight_, t_cpnt *contact_)
{
	t_figure	*fg_;
	size_t		i;

	i = 0;
	while (i < objs_->figure_cnt_)
	{
		fg_ = objs_->figures_ + i++;
		if (fg_->type_ == type_pl_)
			check_plane(fg_, sight_, contact_);
		else if (fg_->type_ == type_sp_)
			check_sphere(fg_, sight_, contact_);
		else if (fg_->type_ == type_cy_)
			check_cylinder(fg_, sight_, contact_);
	}
	return (contact_->ismeet_);
}

void	get_light(t_objs *objs_, size_t i, t_line3 sight_, t_cpnt *contact_)
{
	t_light	light_;
	t_vec3	raydir_;
	t_vec3	tmp_;
	t_rgb	light_rgb_;
	t_cpnt	cpnt_;

	light_ = objs_->lights_[i];
	cpnt_.tval = dist_dot_dot(contact_->pos_, light_.light_point_);
	if (object_traverse(objs_, line3_by_dots(light_.light_point_
				, contact_->pos_), &cpnt_) && cpnt_.tmin + 0.0001 < cpnt_.tval)
		return ;
	raydir_ = normalize_vec3(sub_vec3(light_.light_point_, contact_->pos_));
	cpnt_.dffs = fmax(dot_product(contact_->normal_, raydir_), 0.0);
	tmp_ = times_vec3(tangent_vec3(raydir_, contact_->normal_), -2);
	raydir_ = add_vec3(raydir_, tmp_);
	cpnt_.spclr = pow(fmax(dot_product(sight_.dir_, raydir_), 0.0), KSN_);
	cpnt_.incrm = (cpnt_.spclr * KS_ + cpnt_.dffs) * light_.ratio_ * LUMEN;
	light_rgb_ = times_vec3(color_to_rgb(light_.color_), cpnt_.incrm);
	contact_->rgb_ = add_vec3(contact_->rgb_, light_rgb_);
}
