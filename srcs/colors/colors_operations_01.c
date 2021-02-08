/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:08:21 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/05 20:22:23 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static double		fit_value(double value)
{
	if (value > 255)
		return (255);
	else if (value < 0)
		return (0);
	else
		return (value);
}

t_colors			fit_color(t_colors a)
{
	t_colors	fit;

	fit.a = fit_value(a.a);
	fit.r = fit_value(a.r);
	fit.g = fit_value(a.g);
	fit.b = fit_value(a.b);
	return (fit);
}

int					argb_to_int(t_colors color)
{
	int			alpha;
	int			red;
	int			green;
	int			blue;

	alpha = (int)(color.a);
	red = (int)(color.r);
	green = (int)(color.g);
	blue = (int)(color.b);
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

t_colors			hadamard_product(t_colors a, t_colors b)
{
	t_colors	prod;

	prod.a = a.a * b.a;
	prod.r = a.r * b.r;
	prod.g = a.g * b.g;
	prod.b = a.b * b.b;
	return (prod);
}
