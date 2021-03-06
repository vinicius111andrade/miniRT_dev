/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:08:21 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 18:17:07 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolors.h"

static double		fit_value(double value)
{
	if (value > 1)
		return (1);
	else if (value < 0)
		return (0);
	else
		return (value);
}

t_colors			refit_colors(t_colors a)
{
	t_colors	fit;

	fit.a = fit_value(a.a);
	fit.r = fit_value(a.r);
	fit.g = fit_value(a.g);
	fit.b = fit_value(a.b);
	return (fit);
}

int					argb_to_int(t_colors a)
{
	t_colors	fit;
	int			alpha;
	int			red;
	int			green;
	int			blue;

	fit = refit_colors(a);
	alpha = (int)(fit.a * 255);
	red = (int)(fit.r * 255);
	green = (int)(fit.g * 255);
	blue = (int)(fit.b * 255);
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
