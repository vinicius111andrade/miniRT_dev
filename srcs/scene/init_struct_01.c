/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:56:06 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 18:16:47 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

t_res			*init_res(void)
{
	t_res		*res;

	res = malloc(sizeof(t_res));
	*res = (t_res) {0};
	return (res);
}

t_amb_light		*init_amb_light(void)
{
	t_amb_light	*amb_light;

	amb_light = malloc(sizeof(t_amb_light));
	*amb_light = (t_amb_light) {0};
	return (amb_light);
}

t_cam			*init_cam(void)
{
	t_cam		*cam;

	cam = malloc(sizeof(t_cam));
	*cam = (t_cam) {0};
	return (cam);
}

t_light			*init_light(void)
{
	t_light		*light;

	light = malloc(sizeof(t_light));
	*light = (t_light) {0};
	return (light);
}

t_pl			*init_pl(void)
{
	t_pl		*pl;

	pl = malloc(sizeof(t_pl));
	*pl = (t_pl) {0};
	return (pl);
}
