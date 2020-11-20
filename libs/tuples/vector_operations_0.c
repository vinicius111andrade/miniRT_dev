/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:23:33 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/20 21:59:36 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

t_tuples		tup_define(double x, double y, double z, double w)
{
	t_tuples	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_tuples		tup_invert_direction(t_tuples vector)
{
	t_tuples	inversion;

	inversion.x = -(vector.x);
	inversion.y = -(vector.y);
	inversion.z = -(vector.z);
	inversion.w = vector.w;
	return (inversion);
}

t_tuples		tup_add(t_tuples a, t_tuples b)
{
	t_tuples	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	sum.w = a.w;
	return (sum);
}

t_tuples		tup_subtract(t_tuples a, t_tuples b)
{
	return (tup_add(a, tup_invert_direction(b)));
}

double			tup_dotproduct(t_tuples a, t_tuples b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
