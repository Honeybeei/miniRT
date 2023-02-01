/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:06:00 by seoyoo            #+#    #+#             */
/*   Updated: 2023/02/01 18:00:11 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

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
		//else if (fgr->type_ == type_cy_)
		//	cylinder_traverse();
	}
	return (contact_->ismeet_);
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
