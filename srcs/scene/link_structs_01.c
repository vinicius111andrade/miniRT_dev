/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_structs_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:54:48 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 22:22:37 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minirt.h"

void	link_cam(t_scene *scene, t_cam *new_cam)
{
	t_cam	*last_cam;

	last_cam = scene->cam;
	if (last_cam->next)
		msg("000");
	// while (last_cam->next)
	// {
	// 	msg("000");
	// 	last_cam = last_cam->next;
	// 	msg("000");
	// }
	msg("000");
	last_cam->next = new_cam;
}
