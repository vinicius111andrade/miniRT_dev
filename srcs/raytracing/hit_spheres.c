/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:50:00 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 22:16:35 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** hit sp test one sphere and returns 1 if it hits else 0
** hit spheres test all spheres and return 1 if i hit at least one
*/

// bool			hit_sp(t_ray *ray, t_elem *elem)
// {
// 	t_coord		v_sp2ray;
// 	float		time[2];

// 	v_sp2ray = v_sub(ray->p_ori, elem->point);
// 	bhaskara(v_len_sqr(ray->v_dir), 2 * v_dot(ray->v_dir, v_sp2ray),
// 				v_dot(v_sp2ray, v_sp2ray) - pow(elem->diam / 2, 2), time);
// 	if (ray->hit.time > time[0] && time[0] > 0)
// 	{
// 		ray->hit.time = time[0];
// 		ray->hit.point = get_hit_point(*ray);
// 		ray->hit.normal = v_norm(v_sub(ray->hit.point, elem->point));
// 		ray->hit.colour = elem->colour;
// 		return (true);
// 	}
// 	return (false);
// }

// static bool		intersect(t_rt *rt, t_ray *ray)
// {
// 	bool				ret;

// 	ray->hit.time = INFINITY;
// 	ret = false;
// 	if (rt->scene.sp != 0)
// 		iter_lst_objs(ray, rt->scene.sp, &ret, *hit_sp);
// 	if (rt->scene.pl != 0)
// 		iter_lst_objs(ray, rt->scene.pl, &ret, *hit_pl);
// 	if (rt->scene.sq != 0)
// 		iter_lst_objs(ray, rt->scene.sq, &ret, *hit_polyg);
// 	if (rt->scene.tr != 0)
// 		iter_lst_objs(ray, rt->scene.tr, &ret, *hit_polyg);
// 	if (rt->scene.cy != 0)
// 		iter_lst_objs(ray, rt->scene.cy, &ret, *hit_cy);
// 	return (ret);
// }

int			hit_this_sphere(t_ray *ray, t_sp *sphere)
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

// static void		iter_lst_objs(t_ray *ray, t_elem *elem, bool *ret,
// 								bool (*ft)(t_ray *ray, t_elem *elem))
// {
// 	while (elem)
// 	{
// 		*ret |= (*ft)(ray, elem);
// 		elem = elem->next;
// 	}
// }

//hit spheres test all spheres and return 1 if i hit at least one

int			hit_all_spheres(t_ray *ray, t_sp *sphere)
{
	int		intersect;
	int		at_least_one_hit;

	at_least_one_hit = 0;
	while (sphere)
	{
		intersect = hit_this_sphere(ray, sphere);
		if (intersect && !(at_least_one_hit))
			at_least_one_hit = 1;
		sphere = sphere->next;
	}
}
