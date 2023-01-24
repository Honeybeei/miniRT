/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:15:36 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/24 15:43:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE SHOULD BE ERASED BEFORE SUBMISSION

#include "../../inc/minirt.h"

static void	test_print_rgb(t_rgb rgb);
static void	test_print_vec3(const char *type, t_vec3 vec);
static void	test_print_double(const char *type, double n);

void	test_print_inputs(t_input *input)
{
	printf("\nTESTING START\n");
	printf("\n\nAmbient lightning\n");
	test_print_double("Ratio", input->ambient_.ratio_);
	test_print_rgb(input->ambient_.rgb_);

	printf("\nCamera\n");
	test_print_vec3("View point", input->camera_.view_point_);
	test_print_vec3("Orientation", input->camera_.orientation_);
	test_print_double("FOV", input->camera_.fov_);

	printf("\nLight\n");
	test_print_vec3("Light point", input->light_.light_point_);
	test_print_double("Ratio", input->light_.ratio_);

	for (int i = 0; i < input->obj_cnt_[type_sphere_]; i++)
	{
		printf("\nSphere [%d]\n", i + 1);
		test_print_vec3("Sphere center", input->sphere_[i].center_);
		test_print_double("Diameter", input->sphere_[i].diameter_);
		test_print_rgb(input->sphere_[i].rgb_);
	}

	for (int i = 0; i < input->obj_cnt_[type_plane_]; i++)
	{
		printf("\nPlane [%d]\n", i + 1);
		test_print_vec3("Coordinate", input->plane_[i].coordinate_);
		test_print_vec3("Orientation", input->plane_[i].orientation_);
		test_print_rgb(input->plane_[i].rgb_);
	}

	for (int i = 0; i < input->obj_cnt_[type_cylinder_]; i++)
	{
		printf("\nCylinder [%d]\n", i + 1);
		test_print_vec3("Coordinate", input->cylinder_[i].coordinate_);
		test_print_vec3("Orientation", input->cylinder_[i].orientation_);
		test_print_double("Diameter", input->cylinder_[i].diameter_);
		test_print_double("Height", input->cylinder_[i].height_);
		test_print_rgb(input->cylinder_[i].rgb_);
	}
	printf("\nTESTING FINISHED\n\n");
}

static void	test_print_rgb(t_rgb rgb)
{
	printf("RGB: (%d, %d, %d)\n", rgb[r_], rgb[g_], rgb[b_]);
}

static void	test_print_vec3(const char *type, t_vec3 vec)
{
	printf("%s: (%f, %f, %f)\n", type, vec[x_], vec[y_], vec[z_]);
}

static void	test_print_double(const char *type, double n)
{
	printf("%s: %f\n", type, n);
}