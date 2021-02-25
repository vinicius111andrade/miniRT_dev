/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:13:39 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/25 21:23:40 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray			gen_ray(t_cam *cam, float x, float y)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direction = v_add(v_scale(cam->hor, x), v_scale(cam->ver, y));
	ray.direction = v_add(ray.direction, cam->llc);
	ray.direction = v_norm(v_sub(ray.direction, ray.origin));
	ft_bzero(&ray.hit, 0);
	return (ray);
}
