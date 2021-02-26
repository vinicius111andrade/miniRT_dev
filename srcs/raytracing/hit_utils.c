/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:54:05 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 20:10:02 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		bhaskara(double a, double b, double c, double *res)
{
	double		sqrt_discriminant;
	double		solutions[2];

	sqrt_discriminant = sqrt(pow(b, 2) - 4 * a * c);
	solutions[0] = (-b - sqrt_discriminant) / (2 * a);
	solutions[1] = (-b + sqrt_discriminant) / (2 * a);
	if (solutions[0] < solutions[1])
	{
		res[0] = solutions[0];
		res[1] = solutions[1];
	}
	else
	{
		res[0] = solutions[1];
		res[1] = solutions[0];
	}
}

t_tuples	get_hit_point(t_ray ray)
{
	t_tuples	point;

	point = scale_tuples(ray.hit.time, ray.direction);
	point = add_tuples(point, ray.origin);
	return (point);
}
