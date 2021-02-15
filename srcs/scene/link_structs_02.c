/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_structs_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:51:09 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 21:52:47 by vde-melo         ###   ########.fr       */
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
