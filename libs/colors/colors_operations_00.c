/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations_00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:17:07 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 16:26:29 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolors.h"

t_colors		colors(double a, double r, double g, double b)
{
	t_colors	new;

	new.a = a;
	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

t_colors		add_colors(t_colors a, t_colors b)
{
	t_colors	sum;

	sum.a = a.a + b.a;
	sum.r = a.r + b.r;
	sum.g = a.g + b.g;
	sum.b = a.b + b.b;
	return (sum);
}

t_colors		sub_colors(t_colors a, t_colors b)
{
	t_colors	sub;

	sub.a = a.a - b.a;
	sub.r = a.r - b.r;
	sub.g = a.g - b.g;
	sub.b = a.b - b.b;
	return (sub);
}

t_colors		scale_colors(double scalar, t_colors a)
{
	t_colors	scale;

	scale.a = scalar * a.a;
	scale.r = scalar * a.r;
	scale.g = scalar * a.g;
	scale.b = scalar * a.b;
	return (scale);
}

t_colors		norm_colors(t_colors a)
{
	t_colors	norm;

	norm.a = a.a / 255;
	norm.r = a.r / 255;
	norm.g = a.g / 255;
	norm.b = a.b / 255;
	return (norm);
}
