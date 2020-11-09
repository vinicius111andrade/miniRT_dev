/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:27:25 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/05 21:46:18 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

/*
**	v_distance calculates the distance between the points that are at
**		the end of vectors v1 and v2
**
**	To rotate a vector we use a 3x3 rotation matrix, to simplify the
**		calculation the matrix is divided in 3 rows. We also convert
**		the given angle to radians.
*/

t_vector		v_scale(double scalar, t_vector vec)
{
	t_vector	new_vec;

	new_vec.x = scalar * vec.x;
	new_vec.y = scalar * vec.y;
	new_vec.z = scalar * vec.z;
	return (new_vec);
}

double			v_distance(t_vector v1, t_vector v2)
{
	double		d;

	d = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	return (d);
}

t_vector		x_axis_rotation(t_vector vec, double deg_angle)
{
	t_vector	row1;
	t_vector	row2;
	t_vector	row3;
	t_vector	rotated;
	double		rad_angle;

	rad_angle = deg_angle * M_PI / 180;
	row1 = (t_vector){1, 0, 0};
	row2 = (t_vector){0, cos(rad_angle), -sin(rad_angle)};
	row3 = (t_vector){0, sin(rad_angle), cos(rad_angle)};
	rotated.x = vec.x * row1.x + vec.y * row1.y + vec.z * row1.z;
	rotated.y = vec.x * row2.x + vec.y * row2.y + vec.z * row2.z;
	rotated.z = vec.x * row3.x + vec.y * row3.y + vec.z * row3.z;
	return (rotated);
}

t_vector		y_axis_rotation(t_vector vec, double deg_angle)
{
	t_vector	row1;
	t_vector	row2;
	t_vector	row3;
	t_vector	rotated;
	double		rad_angle;

	rad_angle = deg_angle * M_PI / 180;
	row1 = (t_vector){cos(rad_angle), 0, sin(rad_angle)};
	row2 = (t_vector){0, 1, 0};
	row3 = (t_vector){-sin(rad_angle), 0, cos(rad_angle)};
	rotated.x = vec.x * row1.x + vec.y * row1.y + vec.z * row1.z;
	rotated.y = vec.x * row2.x + vec.y * row2.y + vec.z * row2.z;
	rotated.z = vec.x * row3.x + vec.y * row3.y + vec.z * row3.z;
	return (rotated);
}

t_vector		z_axis_rotation(t_vector vec, double deg_angle)
{
	t_vector	row1;
	t_vector	row2;
	t_vector	row3;
	t_vector	rotated;
	double		rad_angle;

	rad_angle = deg_angle * M_PI / 180;
	row1 = (t_vector){cos(rad_angle), -sin(rad_angle), 0};
	row2 = (t_vector){sin(rad_angle), cos(rad_angle), 0};
	row3 = (t_vector){0, 0, 1};
	rotated.x = vec.x * row1.x + vec.y * row1.y + vec.z * row1.z;
	rotated.y = vec.x * row2.x + vec.y * row2.y + vec.z * row2.z;
	rotated.z = vec.x * row3.x + vec.y * row3.y + vec.z * row3.z;
	return (rotated);
}
