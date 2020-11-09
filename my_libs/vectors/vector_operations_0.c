/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:23:33 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/05 20:49:53 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

t_vector		v_define(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector		v_invert_direction(t_vector vector)
{
	t_vector	inversion;

	inversion.x = -(vector.x);
	inversion.y = -(vector.y);
	inversion.z = -(vector.z);
	return (inversion);
}

t_vector		v_add(t_vector a, t_vector b)
{
	t_vector	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

t_vector		v_subtract(t_vector a, t_vector b)
{
	return (v_add(a, v_invert_direction(b)));
}

double			v_dotproduct(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
