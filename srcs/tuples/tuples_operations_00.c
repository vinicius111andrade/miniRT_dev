/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations_00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:17:07 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/25 20:10:08 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tuples.h"

t_tuples		point(double x, double y, double z)
{
	t_tuples	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 1;
	return (tuple);
}

t_tuples		vector(double x, double y, double z)
{
	t_tuples	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 0;
	return (tuple);
}

t_tuples		add_tuples(t_tuples a, t_tuples b)
{
	t_tuples	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	sum.w = a.w + b.w;
	return (sum);
}

t_tuples		sub_tuples(t_tuples a, t_tuples b)
{
	t_tuples	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	sub.w = a.w - b.w;
	return (sub);
}

t_tuples		neg_tuples(t_tuples a)
{
	t_tuples	neg;

	neg.x = -a.x;
	neg.y = -a.y;
	neg.z = -a.z;
	neg.w = -a.w;
	return (neg);
}
