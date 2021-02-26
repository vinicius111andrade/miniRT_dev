/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:50:00 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 22:43:27 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** hit_this_sphere test one sphere and returns 1 if it hits else 0
*/

static int		hit_this_sphere(t_ray *ray, t_sp *sphere)
{
	t_tuples	sp2ray;
	double		time[2];

	sp2ray = sub_tuples(ray->origin, sphere->origin);
	bhaskara(magnitude(ray->direction) * magnitude(ray->direction),
			2 * dotproduct(ray->direction, sp2ray),
			dotproduct(sp2ray, sp2ray) - pow(sphere->diameter / 2, 2), time);
	if (ray->hit.time > time[0] && time[0] > 0)
	{
		ray->hit.time = time[0];
		ray->hit.point = get_hit_point(*ray);
		ray->hit.normal = normalize(sub_tuples(ray->hit.point, sphere->origin));
		ray->hit.color = sphere->color;
		return (1);
	}
	return (0);
}

/*
** hit_all_spheres test all spheres and return 1 if it hits at least one
*/

int				hit_all_spheres(t_ray *ray, t_sp *sphere)
{
	int			intersect;
	int			at_least_one_hit;

	at_least_one_hit = 0;
	while (sphere)
	{
		intersect = hit_this_sphere(ray, sphere);
		if (intersect && !(at_least_one_hit))
			at_least_one_hit = 1;
		sphere = sphere->next;
	}
	return (intersect);
}
