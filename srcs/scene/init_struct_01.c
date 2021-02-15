/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:56:06 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 22:54:07 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_res			*init_res(void)
{
	return (t_res *)ft_calloc(1, sizeof(t_res));
}

t_amb_light		*init_amb_light(void)
{
	return (t_amb_light *)ft_calloc(1, sizeof(t_amb_light));
}

t_cam			*init_cam(void)
{
	t_cam		*cam;

	cam = ft_calloc(1, sizeof(t_cam));
	cam->next = NULL;
	return (cam);
}

t_light			*init_light(void)
{
	t_light		*light;

	light = ft_calloc(1, sizeof(t_light));
	light->next = NULL;
	return (light);
}

t_pl			*init_pl(void)
{
	t_pl		*pl;

	pl = ft_calloc(1, sizeof(t_pl));
	pl->next = NULL;
	return (pl);
}
