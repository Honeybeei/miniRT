/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 18:18:16 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
/*
typedef	struct s_contacting_point
{
	t_dot3		pos_;
	double		tmin;
	t_bool		ismeet_;
	t_figure	*fg_;
	t_rgb		rgb_;

		// albedo라든지...	// color라든지....	// nearest light라든지..
	// ultimate environment에 대한 참조포인터라든지..
}	t_cpnt;

//	draw_all.c
void	draw_all(t_mlx *mlx_, t_img *img_, t_objs *objs_);
t_dot3	set_screen(t_screen *screen_, t_camera camera_);
t_color process_pixel(t_objs *objs_, t_line3 sight_);
t_vec3	get_normal(t_pvec3 pos_, t_line3 sight_, t_figure *fg_);

//	traverse.c
t_bool	object_traverse(t_objs *objs_, t_line3 sight_, t_cpnt *contact_)
void	check_plane(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
void	check_sphere(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
void	tmin_update(t_figure *fg_, t_line3 sight_, t_cpnt *ct_, double tval);
*/


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

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


/* ************************************************************************** */

t_vec3	get_normal(t_pvec3 pos_, t_line3 sight_, t_figure *fg_)
{
	t_vec3	v_;
	double	tmp;

	if (fg_->type_ == type_pl_)
	{
		tmp = dot_product(fg_->dir_, sight_.dir_);
		return (times_vec3(fg_->dir_, (tmp < 0.0) - (0.0 < tmp)));
	}
	else if (fg_->type_ == type_sp_)
	{
		v_ = sub_vec3(pos_, fg_->pos_);
		tmp = dot_product(v_, sight_.dir_);
		return (times_vec3(normalize_vec3(v_), (tmp <= 0.0) - (0.0 < tmp)));
	}
	else // 사실상 실행이 안되는 부분임 컴파일때문에 넣어 둠
	{
		printf("what the fuck this figure? I can't get a normal vector\n");
		return (regular_vec3(STD_Y));
	}
//	else if (fg_->type_ == type_cy_)
//		return ();
}

t_color	process_pixel(t_objs *objs_, t_line3 sight_)
{
	t_cpnt	contact_;
	t_rgb	delta_;
//	size_t	i;

	
	delta_ = objs_->ambient_.increment_;
	contact_.rgb_ = regular_vec3(ZERO);
	if (object_traverse(objs_, sight_, &contact_))
	{
		contact_.normal_ = get_normal(contact_.pos_, sight_, contact_.fg_);
//		i = 0;
//		while (i < objs_->light_cnt_)
//			get_light(objs_->lights[i++], sight_, &contact_);
		delta_ = times_vec3(objs_->ambient_.increment_, contact_.fg_->albedo);
		return (rgb_to_color(add_vec3(contact_.rgb_, delta_)));
	}
	else
		return (rgb_to_color(objs_->ambient_.increment_));
}

/*
void	get_light_(t_light light_, t_line3 sight_, t_cpnt *contact_)
{


	// 1.1.1을 넘어가면 1.1.1로 두는 연산을 계속해줘야해
	// 즉, fmin(255.0)을 해조야 한다는 것이지.
	// 근데 마지막에 어차피 하긴 하는데, 중간 과정에서도 사이사이 내림이 드가야할까?
	// 고민해봐야하는 지점임.
	//
	// 닥치고 일단 normal 공식부터 짜 
}
*/
//t_vec3	phong_light_process(t_light light_, t_line3 sight_, t_cpnt *contact_)
//{

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


	// 2. ksn
	// ks : specular constant setting[0,1] (maybe from objs_ struct, world own trait)
	// ksn : shininess value of object (256)
//}

