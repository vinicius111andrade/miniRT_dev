/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:06:08 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 18:18:45 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLORS_H
# define LIBCOLORS_H

typedef struct	s_colors
{
	double		a;
	double		r;
	double		g;
	double		b;
}				t_colors;

t_colors		colors(double a, double r, double g, double b);
t_colors		add_colors(t_colors a, t_colors b);
t_colors		sub_colors(t_colors a, t_colors b);
t_colors		scale_colors(double scalar, t_colors a);
t_colors		norm_colors(t_colors a);
t_colors		refit_colors(t_colors a);
int				argb_to_int(t_colors a);
t_colors		hadamard_product(t_colors a, t_colors b);

#endif
