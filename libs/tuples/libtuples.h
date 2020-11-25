/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtuples.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:06:08 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/25 20:21:48 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTUPLES_H
# define LIBTUPLES_H

# include <math.h>

typedef struct	s_tuples
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_tuples;

t_tuples		point(double x, double y, double z);
t_tuples		vector(double x, double y, double z);
t_tuples		add_tuples(t_tuples a, t_tuples b);
t_tuples		sub_tuples(t_tuples a, t_tuples b);
t_tuples		neg_tuples(t_tuples a);
t_tuples		scale_tuples(double scalar, t_tuples a);
double			dotproduct(t_tuples a, t_tuples b);
double			magnitude(t_tuples v);

#endif