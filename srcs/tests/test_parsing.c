/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:19:57 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 20:17:54 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_parsing(t_scene *scene)
{
	t_res			*res;
	t_amb_light		*amb_light;
	t_colors		color;
	t_cam			*cam;
	t_tuples		cam_origin;
	t_tuples		cam_direction;
	int				cam_nb;


	res = scene->res;
	amb_light = scene->amb_light;
	color = amb_light->color;
	cam = scene->cam;
	
	printf("resolution x = %f, y = = %f\n", res->x, res->y); //printf
	printf("amb light brigth = %f, r = %f, g = %f, b = %f\n", amb_light->brightness, color.r, color.g, color.b);
	cam_nb = 1;
	while (cam != 0)
	{
		cam_origin = cam->origin;
		cam_direction = cam->direction;

		printf("Camera number %d\n", cam_nb);
		printf("Camera Origin: x = %f, y = %f, z = %f\n", cam_origin.x, cam_origin.y, cam_origin.z);
		printf("Camera Direction: x = %f, y = %f, z = %f\n", cam_direction.x, cam_direction.y, cam_direction.z);
		printf("Camera FOV %f\n", cam->fov);


		cam_nb++;
		cam = cam->next;
	}
}
