/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:59:11 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/05 20:50:59 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTORS_H
# define LIBVECTORS_H

# include <math.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector		v_define(double x, double y, double z);
t_vector		v_invert_direction(t_vector vector);
t_vector		v_add(t_vector a, t_vector b);
t_vector		v_subtract(t_vector a, t_vector b);
double			v_dotproduct(t_vector a, t_vector b);

t_vector		v_crossproduct(t_vector a, t_vector b);
double			v_length(t_vector v);
t_vector		v_normalize(t_vector p);
double			v_cos(t_vector a, t_vector b);
double			v_sin(t_vector a, t_vector b);

t_vector		v_scale(double scalar, t_vector p);
double			v_distance(t_vector p1, t_vector p2);
t_vector		x_axis_rotation(t_vector vec, double deg_angle);
t_vector		y_axis_rotation(t_vector vec, double deg_angle);
t_vector		z_axis_rotation(t_vector vec, double deg_angle);

#endif
