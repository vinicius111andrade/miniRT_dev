/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:19:57 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 22:13:10 by vde-melo         ###   ########.fr       */
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
	test_sphere_parsing(scene);
	test_square_parsing(scene);
	test_cylinder_parsing(scene);
	test_triangle_parsing(scene);
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

void	test_sphere_parsing(t_scene *scene)
{
	t_sp			*sphere;
	t_tuples		origin;
	double			diameter;
	t_colors		color;
	int				sphere_nb;

	sphere = scene->sp;
	sphere_nb = 1;
	printf("\n\nTESTING SPHERES\n");
	while (sphere != NULL)
	{
		origin = sphere->origin;
		diameter = sphere ->diameter;
		color = sphere->color;

		printf("\nSphere Number %d\n", sphere_nb);
		printf("Sphere Origin: x = %f, y = %f, z = %f\n", origin.x, origin.y, origin.z);
		printf("Sphere Diameter: %f\n", diameter);
		printf("Sphere Color r = %f, g = %f, b = %f\n", color.r, color.g, color.b);;

		sphere_nb++;
		sphere = sphere->next;
	}
}

void	test_square_parsing(t_scene *scene)
{
	t_sq			*square;
	t_tuples		origin;
	t_tuples		normal;
	double			side;
	t_colors		color;
	int				square_nb;

	square = scene->sq;
	square_nb = 1;
	printf("\n\nTESTING SPHERES\n");
	while (square != NULL)
	{
		origin = square->origin;
		normal = square->normal;
		side = square ->side;
		color = square->color;

		printf("\nSquare Number %d\n", square_nb);
		printf("Square Origin: x = %f, y = %f, z = %f\n", origin.x, origin.y, origin.z);
		printf("Square Normal: x = %f, y = %f, z = %f\n", normal.x, normal.y, normal.z);
		printf("Square Side: %f\n", side);
		printf("Square Color r = %f, g = %f, b = %f\n", color.r, color.g, color.b);;

		square_nb++;
		square = square->next;
	}
}

void	test_cylinder_parsing(t_scene *scene)
{
	t_cy			*cylinder;
	t_tuples		origin;
	t_tuples		normal;
	double			diameter;
	double			height;
	t_colors		color;
	int				cylinder_nb;

	cylinder = scene->cy;
	cylinder_nb = 1;
	printf("\n\nTESTING CYLINDERS\n");
	while (cylinder != NULL)
	{
		origin = cylinder->origin;
		normal = cylinder->normal;
		diameter = cylinder ->diameter;
		height = cylinder ->height;
		color = cylinder->color;

		printf("\nCylinder Number %d\n", cylinder_nb);
		printf("Cylinder Origin: x = %f, y = %f, z = %f\n", origin.x, origin.y, origin.z);
		printf("Cylinder Normal: x = %f, y = %f, z = %f\n", normal.x, normal.y, normal.z);
		printf("Cylinder Diameter: %f\n", diameter);
		printf("Cylinder Height: %f\n", height);
		printf("Cylinder Color r = %f, g = %f, b = %f\n", color.r, color.g, color.b);;

		cylinder_nb++;
		cylinder = cylinder->next;
	}
}

void	test_triangle_parsing(t_scene *scene)
{
	t_tr			*triangle;
	t_tuples		p1;
	t_tuples		p2;
	t_tuples		p3;
	t_colors		color;
	int				triangle_nb;

	triangle = scene->tr;
	triangle_nb = 1;
	printf("\n\nTESTING TRIANGLES\n");
	while (triangle != NULL)
	{
		p1 = triangle->p1;
		p2 = triangle->p2;
		p3 = triangle->p3;
		color = triangle->color;

		printf("\nTriangle Number %d\n", triangle_nb);
		printf("Triangle Point 1: x = %f, y = %f, z = %f\n", p1.x, p1.y, p1.z);
		printf("Triangle Point 2: x = %f, y = %f, z = %f\n", p2.x, p2.y, p2.z);
		printf("Triangle Point 3: x = %f, y = %f, z = %f\n", p3.x, p3.y, p3.z);
		printf("Triangle Color r = %f, g = %f, b = %f\n", color.r, color.g, color.b);;

		triangle_nb++;
		triangle = triangle->next;
	}
}
