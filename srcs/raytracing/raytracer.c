/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:17:38 by vde-melo          #+#    #+#             */
/*   Updated: 2021/03/01 18:33:40 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		check_intersection(t_rt *rt, t_ray *ray)
{
	int			intersect;

	ray->hit.time = INFINITY;
	intersect = 0;

	// here it goes through every object in the list

	// test_spheres vai iterar por cada sp e se qlqr hit_sp retornar 1 ela retorna 1 tbm
	if (rt->scene.sp != 0)
		intersect = hit_all_spheres(ray, rt->scene.sp);
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
	return (check_intersection(rt, &shadow));
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
								(4.0 * PI_L12 * r2);
	return (hadamard_product(
				fit_color(scale_colors(light_brightness, hit.color)),
				light->color));
}


int				raytrace(t_rt *rt, t_ray *ray)
{
	t_colors	amb_color;
	t_colors	color;
	t_light		*light;
	int			argb;

	if (check_intersection(rt, ray) == 0)
		return (0);
	amb_color = scale_colors(rt->scene.amb_light->brightness,
								rt->scene.amb_light->color);
	color = hadamard_product(ray->hit.color, amb_color);
	light = rt->scene.light;
	while (light)
	{
		if(!is_in_shadow(rt, ray->hit, light)) //vis not needed i think, it just nulifies the color add when it is in shadow
			color = add_colors(color, c_comp(light, ray->hit));
		light = light->next;
	}
	argb = argb_to_int(fit_color(color)); //ver se o alpha ta correto, ta setado pra 255
	return (argb);
}
