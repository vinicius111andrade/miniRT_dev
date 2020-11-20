/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:54:51 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/20 22:01:06 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"
#include <math.h>

t_tuples		v_crossproduct(t_tuples a, t_tuples b)
{
	t_tuples	product;

	product.x = a.y * b.z - a.z * b.y;
	product.y = a.z * b.x - a.x * b.z;
	product.z = a.x * b.y - a.y * b.x;
	product.w = a.w;
	return (product);
}

double			v_length(t_tuples v)
{
	return (sqrt(v_dotproduct(v, v)));
}

t_tuples		v_normalize(t_tuples vec)
{
	t_tuples	unit_vec;
	double		norm;

	norm = v_length(vec);
	unit_vec.x = vec.x / norm;
	unit_vec.y = vec.y / norm;
	unit_vec.z = vec.z / norm;
	unit_vec.w = vec.w;
	return (unit_vec);
}

double			v_cos(t_tuples a, t_tuples b)
{
	return (v_dotproduct(a, b) / (v_length(a) * v_length(b)));
}

double			v_sin(t_tuples a, t_tuples b)
{
	return (sqrt(1 - pow(v_cos(a, b), 2)));
}
