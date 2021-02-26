/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:13:39 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 17:12:49 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray			gen_ray(t_cam *cam, double x, double y)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direction = add_tuples(scale_tuples(x, cam->hor),
						scale_tuples(y, cam->ver));
	ray.direction = add_tuples(ray.direction, cam->llc);
	ray.direction = normalize(sub_tuples(ray.direction, ray.origin));
	ft_bzero(&ray.hit, 0);
	return (ray);
}
