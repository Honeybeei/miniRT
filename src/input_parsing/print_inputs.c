/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:47:48 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/31 12:31:44 by seoyoo           ###   ########.fr       */
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
	printf("\nAmbient | ");
	printf("ratio: %f | ", ambient->ratio_);
	printf("color: %x\n", ambient->color_);
}

static void	print_camera(t_camera *camera)
{
	printf("Camera |");
	printf("view point: (%f, %f, %f) | ", camera->pos_.e[x_], \
	camera->pos_.e[y_], camera->pos_.e[z_]);
	printf("orientation: (%f, %f, %f) | ", camera->dir_.e[x_], \
	camera->dir_.e[y_], camera->dir_.e[z_]);
	printf("fov: %f\n", camera->fov_);
}

static void	print_light(t_light *light, int i)
{
	printf("Light [%d] | ", i);
	printf("light point: (%f, %f, %f) | ", light->light_point_.e[x_], \
	light->light_point_.e[y_], light->light_point_.e[z_]);
	printf("brightness: %f | ", light->ratio_);
	printf("color: %x\n", light->color_);
}

static void	print_figure(t_figure *figure, int i)
{
	printf("Figure [%d] | ", i);
	printf("Type: ");
	if (figure->type_ == type_pl_)
		printf("plane    | ");
	else if (figure->type_ == type_sp_)
		printf("sphere   | ");
	else if (figure->type_ == type_cy_)
		printf("cylinder | ");
	else
		printf("TYPE ERROR | ");
	printf("color: %0.6x | ", figure->clr_);
	printf("position: (%15.6f, %15.6f, %15.6f) | ", figure->pos_.e[x_], \
	figure->pos_.e[y_], figure->pos_.e[z_]);
	printf("direction: (%15.6f, %15.6f, %15.6f) | ", figure->dir_.e[x_], \
	figure->dir_.e[y_], figure->dir_.e[z_]);
	printf("radius: %15.6f | ", figure->r_);
	printf("height: %15.6f | ", figure->h_);
	printf("obj addr: %p\n", figure->obj_);
}
