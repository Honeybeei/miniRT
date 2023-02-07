/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cntl_mode_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:13:20 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/08 00:17:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	change_figure_designation(t_objs *objs, int key_code);
static void	figure_parallel_translation(t_figure *figure, int key_code);
static void	change_scalar_designation(t_figure *figure, int key_code);
static void change_scalar_value(t_figure *figure, int key_code);
static void	figure_rotation(t_figure *figure, int key_code);

void	figure_cntl_mode_key_press_event(int key_code, t_ptrs *ptrs)
{
	int	i;

	i = 0;
	while (ptrs->objs_.figures_[i].is_pointed_ == false)
		i++;
	if (key_code == key_comma_ || key_code == key_full_stop_)
		change_figure_designation(&ptrs->objs_, key_code);
	else if (key_code == key_a_ || key_code == key_s_ || key_code == key_d_ || \
	key_code == key_q_ || key_code == key_w_ || key_code == key_e_)
		figure_parallel_translation(&ptrs->objs_.figures_[i], key_code);
	else if (key_code == key_square_bracket_start_ || key_code == key_square_bracket_end_)
		change_scalar_designation(&ptrs->objs_.figures_[i], key_code);
	else if (key_code == key_minus_ || key_code == key_equal_)
		change_scalar_value(&ptrs->objs_.figures_[i], key_code);
	else if (key_code == key_left_ || key_code == key_right_ || \
	key_code == key_down_ || key_code == key_up_)
		figure_rotation(&ptrs->objs_.figures_[i], key_code);
	if (ptrs->objs_.figures_[i].type_ == type_cy_)
		init_cy(&ptrs->objs_.figures_[i]);
	print_screen(ptrs, false);
}

static void	change_figure_designation(t_objs *objs, int key_code)
{
	int	i;

	i = 0;
	while (objs->figures_[i].is_pointed_ == false)
		i++;
	objs->figures_[i].is_pointed_ = false;
	i += objs->figure_cnt_;
	if (key_code == key_comma_)
		i = (i - 1) % objs->figure_cnt_;
	else
		i = (i + 1) % objs->figure_cnt_;
	objs->figures_[i].is_pointed_ = true;
	printf("Designated figure [%d]\n", i + 1);
}

static void	figure_parallel_translation(t_figure *figure, int key_code)
{
	if (key_code == key_w_)
		figure->pos_.e[x_] += FIGURE_TRANSLATION_GAP_;
	else if (key_code == key_s_)
		figure->pos_.e[x_] -= FIGURE_TRANSLATION_GAP_;
	else if (key_code == key_d_)
		figure->pos_.e[z_] += FIGURE_TRANSLATION_GAP_;
	else if (key_code == key_a_)
		figure->pos_.e[z_] -= FIGURE_TRANSLATION_GAP_;
	else if (key_code == key_e_)
		figure->pos_.e[y_] += FIGURE_TRANSLATION_GAP_;
	else if (key_code == key_q_)
		figure->pos_.e[y_] -= FIGURE_TRANSLATION_GAP_;
}

static void	change_scalar_designation(t_figure *figure, int key_code)
{
	figure->scalar_to_change_ += SCALAR_TYPE_CNT_;
	if (key_code == key_square_bracket_start_)
		figure->scalar_to_change_ = (figure->scalar_to_change_ - 1) % SCALAR_TYPE_CNT_;
	else
		figure->scalar_to_change_ = (figure->scalar_to_change_ + 1) % SCALAR_TYPE_CNT_;
}

static void change_scalar_value(t_figure *figure, int key_code)
{
	if (figure->scalar_to_change_ == scalar_type_clr_)
	{
		if (key_code == key_minus_ && figure->clr_ > 0)
			figure->clr_--;
		else if (key_code == key_equal_ && figure->clr_ < 0xffffff)
			figure->clr_++;
	}
	else if (figure->scalar_to_change_ == scalar_type_r_)
	{
		if (key_code == key_minus_ && figure->r_ > 0)
			figure->r_--;
		else if (key_code == key_equal_)
			figure->r_++;
	}
	else if (figure->scalar_to_change_ == scalar_type_h_)
	{
		if (key_code == key_minus_ && figure->h_ > 0)
			figure->h_--;
		else if (key_code == key_equal_)
			figure->h_++;
	}
}

static void	figure_rotation(t_figure *figure, int key_code)
{
	if (key_code == key_left_)
		figure->dir_ = rotate_vector(figure->dir_, regular_vec3(STD_Y), \
		-FIGURE_ROTATION_DEGREE_);
	else if (key_code == key_right_)
		figure->dir_ = rotate_vector(figure->dir_, regular_vec3(STD_Y), \
		+FIGURE_ROTATION_DEGREE_);
	else if (key_code == key_up_)
		figure->dir_ = rotate_vector(figure->dir_, cross_product(figure->dir_, \
		regular_vec3(STD_Y)), -FIGURE_ROTATION_DEGREE_);
	else if (key_code == key_down_)
		figure->dir_ = rotate_vector(figure->dir_, cross_product(figure->dir_, \
		regular_vec3(STD_Y)), +FIGURE_ROTATION_DEGREE_);
}
