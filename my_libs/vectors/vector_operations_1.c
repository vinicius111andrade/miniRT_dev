/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:54:51 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/04 15:35:39 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"
# include <math.h>

t_vector		v_crossproduct(t_vector a, t_vector b)
{
	t_vector	product;

	product.x = a.y * b.z - a.z * b.y;
	product.y = a.z * b.x - a.x * b.z;
	product.z = a.x * b.y - a.y * b.x;
	return (product);
}

double		v_length(t_vector v)
{
	return (sqrt(v_dotproduct(v, v)));
}

t_vector	v_normalize(t_vector vec)
{
	t_vector	unit_vec;
	double		norm;

	norm = v_length(vec);
	unit_vec.x = vec.x / norm;
	unit_vec.y = vec.y / norm;
	unit_vec.z = vec.z / norm;
	return (unit_vec);
}

double		v_cos(t_vector a, t_vector b)
{
	return (v_dotproduct(a, b) / (v_length(a) * v_length(b)));
}

double		v_sin(t_vector a, t_vector b)
{
	return (sqrt(1 - pow(v_cos(a, b), 2)));
}

