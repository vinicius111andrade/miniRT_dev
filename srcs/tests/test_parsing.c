/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:19:57 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 19:06:23 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_parsing(t_scene *scene)
{
	t_res			*res;
	t_amb_light		*amb_light;
	t_colors		color;

	res = scene->res;
	amb_light = scene->amb_light;
	color = amb_light->color;
	
	
	printf("\n\nResolution x = %f, y = = %f\n", res->x, res->y); //printf
	printf("Amb Light Brightness = %f, r = %f, g = %f, b = %f\n", amb_light->brightness, color.r, color.g, color.b);
	test_cam_parsing(scene);
	test_light_parsing(scene);
	test_plane_parsing(scene);
}

void	test_cam_parsing(t_scene *scene)
{
	t_cam			*cam;
	t_tuples		cam_origin;
	t_tuples		cam_direction;
	int				cam_nb;

	cam = scene->cam;
	cam_nb = 1;
	printf("\n\nTESTING CAMERAS\n");
	while (cam != NULL)
	{
		cam_origin = cam->origin;
		cam_direction = cam->direction;

		printf("\nCamera Number %d\n", cam_nb);
		printf("Camera Origin: x = %f, y = %f, z = %f\n", cam_origin.x, cam_origin.y, cam_origin.z);
		printf("Camera Direction: x = %f, y = %f, z = %f\n", cam_direction.x, cam_direction.y, cam_direction.z);
		printf("Camera FOV %f\n", cam->fov);

		cam_nb++;
		cam = cam->next;
	}
}

void	test_light_parsing(t_scene *scene)
{
	t_light			*light;
	t_tuples		light_origin;
	double			brigth;
	t_colors		color;
	int				light_nb;

	light = scene->light;
	light_nb = 1;
	printf("\n\nTESTING LIGHTS\n");
	while (light != NULL)
	{
		light_origin = light->origin;
		brigth = light->brightness;
		color = light->color;

		printf("\nLight Number %d\n", light_nb);
		printf("Light Origin: x = %f, y = %f, z = %f\n", light_origin.x, light_origin.y, light_origin.z);
		printf("Light Brightness: %f\n", brigth);
		printf("Light Color r = %f, g = %f, b = %f\n", color.r, color.g, color.b);;

		light_nb++;
		light = light->next;
	}
}

void	test_plane_parsing(t_scene *scene)
{
	t_pl			*plane;
	t_tuples		origin;
	t_tuples		normal;
	t_colors		color;
	int				plane_nb;

	plane = scene->pl;
	plane_nb = 1;
	printf("\n\nTESTING PLANES\n");
	while (plane != NULL)
	{
		origin = plane->origin;
		normal = plane ->normal;
		color = plane->color;

		printf("\nPlane Number %d\n", plane_nb);
		printf("Plane Origin: x = %f, y = %f, z = %f\n", origin.x, origin.y, origin.z);
		printf("Plane Normal: x = %f, y = %f, z = %f\n", normal.x, normal.y, normal.z);
		printf("Plane Color r = %f, g = %f, b = %f\n", color.r, color.g, color.b);;

		plane_nb++;
		plane = plane->next;
	}
}
