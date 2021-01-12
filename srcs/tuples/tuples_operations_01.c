/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:08:21 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/25 20:33:18 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtuples.h"

t_tuples		scale_tuples(double scalar, t_tuples a)
{
	t_tuples	scale;

	scale.x = scalar * a.x;
	scale.y = scalar * a.y;
	scale.z = scalar * a.z;
	scale.w = a.w;
	return (scale);
}

double			dotproduct(t_tuples a, t_tuples b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double			magnitude(t_tuples v)
{
	return (sqrt(dotproduct(v, v)));
}

t_tuples		normalize(t_tuples v)
{
	t_tuples	unit;
	double		mag;

	mag = magnitude(v);
	unit.x = v.x / mag;
	unit.y = v.y / mag;
	unit.z = v.z / mag;
	unit.w = v.w;
}

t_tuples		crossproduct(t_tuples a, t_tuples b)
{
	t_tuples	product;

	product.x = a.y * b.z - a.z * b.y;
	product.y = a.z * b.x - a.x * b.z;
	product.z = a.x * b.y - a.y * b.x;
	product.w = a.w;
	return (product);
}