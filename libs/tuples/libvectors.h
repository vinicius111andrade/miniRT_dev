/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:50:22 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/20 21:51:40 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef LIBVECTORS_H
# define LIBVECTORS_H

# include <math.h>

typedef struct	s_tuples
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_tuples;

t_tuples		tup_define(double x, double y, double z, double w);
t_tuples		tup_invert_direction(t_tuples tuples);
t_tuples		tup_add(t_tuples a, t_tuples b);
t_tuples		tup_subtract(t_tuples a, t_tuples b);
double			tup_dotproduct(t_tuples a, t_tuples b);

t_tuples		tup_crossproduct(t_tuples a, t_tuples b);
double			tup_length(t_tuples v);
t_tuples		tup_normalize(t_tuples p);
double			tup_cos(t_tuples a, t_tuples b);
double			tup_sin(t_tuples a, t_tuples b);

t_tuples		tup_scale(double scalar, t_tuples p);
double			tup_distance(t_tuples p1, t_tuples p2);
t_tuples		x_axis_rotation(t_tuples vec, double deg_angle);
t_tuples		y_axis_rotation(t_tuples vec, double deg_angle);
t_tuples		z_axis_rotation(t_tuples vec, double deg_angle);

#endif
