/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_structs_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:51:09 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 22:08:21 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minirt.h"

void	link_cylinder(t_scene *scene, t_cy *new_cylinder)
{
	t_cy	*last_cylinder;

	last_cylinder = scene->cy;
	if (!last_cylinder)
		scene->cy = new_cylinder;
	else
	{
		while (last_cylinder->next)
			last_cylinder = last_cylinder->next;
		last_cylinder->next = new_cylinder;
	}
}

void	link_triangle(t_scene *scene, t_tr *new_triangle)
{
	t_tr	*last_triangle;

	last_triangle = scene->tr;
	if (!last_triangle)
		scene->tr = new_triangle;
	else
	{
		while (last_triangle->next)
			last_triangle = last_triangle->next;
		last_triangle->next = new_triangle;
	}
}
