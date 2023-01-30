/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:47:48 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/30 15:14:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	print_ambient(t_ambient *ambient);
static void	print_camera(t_camera *camera);
static void	print_light(t_light *light, int i);
static void	print_figure(t_figure *figure, int i);

void	print_inputs(t_objs *objs)
{
	size_t	i;

	print_ambient(&objs->ambient_);
	print_camera(&objs->camera_);
	i = 0;
	while (i < objs->light_cnt_)
	{
		print_light(&objs->lights_[i], i);
		i++;
	}
	i = 0;
	while (i < objs->figure_cnt_)
	{
		print_figure(&objs->figures_[i], i);
		i++;
	}
}

static void	print_ambient(t_ambient *ambient)
{
	printf("\nAmbient\n");
	printf("ratio		: %f	\n", ambient->ratio_);
	printf("color		: %d		\n", ambient->color_);
}

static void	print_camera(t_camera *camera)
{
	printf("\nCamera\n");
	printf("view point	: (%f, %f, %f)\n", camera->pos_.e[x_], \
	camera->pos_.e[y_], camera->pos_.e[z_]);
	printf("orientation	: (%f, %f, %f)\n", camera->dir_.e[x_], \
	camera->dir_.e[y_], camera->dir_.e[z_]);
	printf("fov		: %f\n", camera->fov_);
}

static void	print_light(t_light *light, int i)
{
	printf("\nLight [%d]\n", i);
	printf("light point	: (%f, %f, %f)\n", light->light_point_.e[x_], \
	light->light_point_.e[y_], light->light_point_.e[z_]);
	printf("brightness	: %f\n", light->ratio_);
	printf("color		: %d\n", light->color_);
}

static void	print_figure(t_figure *figure, int i)
{
	printf("\nFigure [%d]\n", i);
	printf("Type		: ");
	if (figure->type_ == type_pl_)
		printf("plane\n");
	else if (figure->type_ == type_sp_)
		printf("sphere\n");
	else if (figure->type_ == type_cy_)
		printf("cylinder\n");
	else
		printf("TYPE ERROR\n");
	printf("color		: %d\n", figure->clr_);
	printf("position	: (%f, %f, %f)\n", figure->pos_.e[x_], \
	figure->pos_.e[y_], figure->pos_.e[z_]);
	printf("direction	: (%f, %f, %f)\n", figure->dir_.e[x_], \
	figure->dir_.e[y_], figure->dir_.e[z_]);
	printf("radius		: %f\n", figure->r_);
	printf("height		: %f\n", figure->h_);
	printf("obj addr	: %p\n", figure->obj_);
}