/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_structs_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:54:48 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 18:10:05 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

void	link_cam(t_scene *scene, t_cam *new_cam)
{
	t_cam	*last_cam;

	last_cam = scene->cam;
	while (last_cam->next != 0)
		last_cam = last_cam->next;
	last_cam->next = new_cam;
}
