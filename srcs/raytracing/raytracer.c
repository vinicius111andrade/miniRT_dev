/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:17:38 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 19:44:31 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		iter_lst_objs(t_ray *ray, t_elem *elem, int *ret,
								int (*ft)(t_ray *ray, t_elem *elem))
{
	while (elem)
	{
		*ret |= (*ft)(ray, elem);
		elem = elem->next;
	}
}

static int		check_intersect(t_rt *rt, t_ray *ray)
{
	int			intersect;

	ray->hit.time = INFINITY;
	intersect = 0;

	// here it goes through every object in the list

	// if (rt->scene.sp != 0)
	// 	iter_lst_objs(ray, rt->scene.sp, &ret, *hit_sp);
	// if (rt->scene.pl != 0)
	// 	iter_lst_objs(ray, rt->scene.pl, &ret, *hit_pl);
	// if (rt->scene.sq != 0)
	// 	iter_lst_objs(ray, rt->scene.sq, &ret, *hit_polyg);
	// if (rt->scene.tr != 0)
	// 	iter_lst_objs(ray, rt->scene.tr, &ret, *hit_polyg);
	// if (rt->scene.cy != 0)
	// 	iter_lst_objs(ray, rt->scene.cy, &ret, *hit_cy);

	return (intersect);// it returns a 1 or a 0 as true or false
}

static int		is_in_shadow(t_rt *rt, t_hit hit, t_light *light)
{
	t_ray	shadow;

	shadow.origin = add_tuples(hit.point, scale_tuples(EPSILON, hit.normal));
	shadow.direction = normalize(sub_tuples(light->origin, shadow.origin));
	return (intersect(rt, &shadow));
}

t_colors		c_comp(t_light *light, t_hit hit)
{
	t_tuples	light_normal;
	double		gain;
	double		r2;
	double		light_brightness;

	light_normal = sub_tuples(light->origin, hit.point);
	r2 = magnitude(light_normal) * magnitude(light_normal);
	gain = dotproduct(normalize(light_normal), hit.normal);
	if (gain <= 0)
		light_brightness = 0;
	else
		light_brightness = (light->brightness * gain * ALBEDO) /
						(4.0 * M_PI * r2);
	return (c_prod(c_add(0, c_scale(hit.color, light_brightness)),
				light->color));
}


int				raytrace(t_rt *rt, t_ray *ray)
{
	t_colors	amb_color;
	t_colors	color;
	t_light		*light;
	int			vis;

	if (intersect(rt, ray) == 0)
		return (0);
	amb_color = scale_colors(rt->scene.amb_light->brightness,
								rt->scene.amb_light->color);
	color = hadamard_product(ray->hit.color, amb_color);
	light = rt->scene.light;
	while (light)
	{
		vis = !in_shadow(rt, ray->hit, light);
		color = add_colors(color, vis * c_comp(light, ray->hit));
		light = light->next;
	}
	return (color);
}
