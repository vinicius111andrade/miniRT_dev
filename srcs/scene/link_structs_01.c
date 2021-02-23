/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_structs_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:54:48 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 19:50:21 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	link_cam(t_scene *scene, t_cam *new_cam)
{
	t_cam	*last_cam;

	last_cam = scene->cam;
	if (!last_cam)
		scene->cam = new_cam;
	else
	{
		while (last_cam->next)
			last_cam = last_cam->next;
		last_cam->next = new_cam;
	}
}

void	link_light(t_scene *scene, t_light *new_light)
{
	t_light	*last_light;

	last_light = scene->light;
	if (!last_light)
		scene->light = new_light;
	else
	{
		while (last_light->next)
			last_light = last_light->next;
		last_light->next = new_light;
	}
}

void	link_plane(t_scene *scene, t_pl *new_plane)
{
	t_pl	*last_plane;

	last_plane = scene->pl;
	if (!last_plane)
		scene->pl = new_plane;
	else
	{
		while (last_plane->next)
			last_plane = last_plane->next;
		last_plane->next = new_plane;
	}
}

void	link_sphere(t_scene *scene, t_sp *new_sphere)
{
	t_sp	*last_sphere;

	last_sphere = scene->sp;
	if (!last_sphere)
		scene->sp = new_sphere;
	else
	{
		while (last_sphere->next)
			last_sphere = last_sphere->next;
		last_sphere->next = new_sphere;
	}
}

void	link_square(t_scene *scene, t_sq *new_square)
{
	t_sq	*last_square;

	last_square = scene->sq;
	if (!last_square)
		scene->sq = new_square;
	else
	{
		while (last_square->next)
			last_square = last_square->next;
		last_square->next = new_square;
	}
}
