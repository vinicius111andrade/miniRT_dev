/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:08:21 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/26 17:01:27 by vde-melo         ###   ########.fr       */
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

t_colors		refit_colors(t_colors a)
{
	t_colors	fit;

	fit.a = fit_value(a.a);
	fit.r = fit_value(a.r);
	fit.g = fit_value(a.g);
	fit.b = fit_value(a.b);
	return (fit);
}

t_colors		final_colors(t_colors a)
{
	t_colors	out;
	t_colors	fit;

	fit = refit_colors(a);
	out.a = fit.a * 255;
	out.r = fit.r * 255;
	out.g = fit.g * 255;
	out.b = fit.b * 255;
	return (out);
}