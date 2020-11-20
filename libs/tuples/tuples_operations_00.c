/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations_00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:17:07 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/20 22:26:38 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

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