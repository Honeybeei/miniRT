/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 16:58:23 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

typedef	struct s_contacting_point
{
	t_dot3		pos_;
	double		tmin;
	t_bool		ismeet_;
	t_figure	*fg_;
//	t_color		endclr_;
	// albedo라든지...	// color라든지....	// nearest light라든지..
	// ultimate environment에 대한 참조포인터라든지..
}	t_cpnt;

#define SCALE_ 0.1

//	draw_all.c
void	draw_all(t_mlx *mlx_, t_img *img_, t_objs *objs_);
t_dot3	set_screen(t_screen *screen_, t_camera camera_);
t_color process_pixel(t_objs *objs_, t_line3 sight_);

//	traverse.c
t_cpnt	object_traverse(t_objs *objs_, t_line3 sight_);
void	check_plane(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
void	check_sphere(t_figure *fg_, t_line3 sight_, t_cpnt *ct_);
void	tmin_update(t_figure *fg_, t_line3 sight_, t_cpnt *ct_, double tval);


int	main(int argc, char *argv[])
{
	t_ptrs	ptrs;

	if (argc < 2)
		error_management(true, err_no_file_, NULL, true);
	else if (argc > 2)
		error_management(true, err_too_much_file_, NULL, true);
	init_mlx(&ptrs);
	parse_input(&ptrs.objs_, argv[1]);
	print_inputs(&ptrs.objs_);
	draw_all(&ptrs.mlx_, &ptrs.img_, &ptrs.objs_);
	mlx_loop(ptrs.mlx_.mlx_ptr_);
	return (0);
}

//////////////////////////////////////////////////////

t_cpnt	object_traverse(t_objs *objs_, t_line3 sight_)
{
	t_figure	*fg_;
	t_cpnt		contact_;
	size_t		i;
	
	contact_.ismeet_ = false_;
	contact_.fg_ = NULL;
	i = 0;
	while (i < objs_->figure_cnt_)
	{
		fg_ = objs_->figures_ + i++;
		if (fg_->type_ == type_pl_)
			check_plane(fg_, sight_, &contact_);
		else if (fg_->type_ == type_sp_)
			check_sphere(fg_, sight_, &contact_);
		//else if (fgr->type_ == type_cy_)
		//	cylinder_traverse();
	}
	return (contact_);
}

void	check_plane(t_figure *fg_, t_line3 sight_, t_cpnt *ct_)
{
	t_vec3	eq_;
	double	tval;

	eq_.e[1] = dot_product(fg_->dir_, sight_.dir_);
	eq_.e[0] = dot_product(fg_->dir_, sub_vec3(sight_.pos_, fg_->pos_));
	if (positive_solution(eq_, &tval))
		tmin_update(fg_, sight_, ct_, tval);
}

void	check_sphere(t_figure *fg_, t_line3 sight_, t_cpnt *ct_)
{
	t_vec3	tmp_;
	t_vec3	eq_;
	double	tval;

	tmp_ = sub_vec3(sight_.pos_, fg_->pos_);
	eq_.e[0] = sqrsum_vec3(tmp_) - fg_->r_ * fg_->r_;
	eq_.e[1] = dot_product(sight_.dir_, tmp_) * 2;
	eq_.e[2] = sqrsum_vec3(sight_.dir_);
	if (positive_solution(eq_ ,&tval))
		tmin_update(fg_, sight_, ct_, tval);
}

void	tmin_update(t_figure *fg_, t_line3 sight_, t_cpnt *ct_, double tval)
{
	if (ct_->ismeet_ == true_ && ct_->tmin < tval)
		return ;
	ct_->tmin = tval;
	ct_->ismeet_ = true_;
	ct_->pos_ = add_vec3(sight_.pos_, times_vec3(sight_.dir_, tval));
	ct_->fg_ = fg_;
}

/* ************************************************************************** */

void	draw_all(t_mlx *mlx_, t_img *img_, t_objs *objs_)
{
	t_screen	screen_;
	t_line3		sight_;
	t_dot3		onscreen_;
//	t_color		pixel_clr;
	size_t		idx[2];

	onscreen_ = set_screen(&screen_, objs_->camera_);
	idx[0] = 0;
	while (idx[0] < WINDOW_HEIGHT_)
	{
		idx[1] = 0;
		while (idx[1] < WINDOW_WIDTH_)
		{
			sight_ = line3_by_dots(objs_->camera_.pos_, onscreen_);
			put_pixel(img_, idx[0], idx[1], process_pixel(objs_, sight_));
			onscreen_ = add_vec3(onscreen_, screen_.hor_unit_);
			idx[1]++;
		}
		onscreen_ = times_vec3(screen_.ver_unit_, ++idx[0]);
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
		return (0x00FFFFFF); // 이상 배경값일때의 임시조치입니당.

}

void	jchoi_put_dots(t_img *img_, int i, int j, int color)
{
	char	*dst;

	dst = img_->addr_ + i * img_->size_line_ + j * (img_->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}
