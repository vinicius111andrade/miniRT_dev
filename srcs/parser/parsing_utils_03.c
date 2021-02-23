/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 23:26:41 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:30:23 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			nonnegative_str_nb(char *str)
{
	if (str[0] == '-')
		return (0);
	return (1);
}

int			is_ratio(double n)
{
	if (n >= 0.0 && n <= 1.0)
		return (1);
	else
		return (0);
}

void		get_rgb(char **rgb, t_colors *color)
{
	color->a = 255;
	color->r = str_to_double(rgb[0]);
	color->g = str_to_double(rgb[1]);
	color->b = str_to_double(rgb[2]);
}

int			validate_rgb_bounds(t_colors color)
{
	if (color.a < 0 || color.a > 255)
		return (0);
	else if (color.r < 0 || color.r > 255)
		return (0);
	else if (color.g < 0 || color.g > 255)
		return (0);
	else if (color.b < 0 || color.b > 255)
		return (0);
	return (1);
}

t_tuples	str_to_tuple(char **xyz, int is_point)
{
	double	x;
	double	y;
	double	z;

	x = str_to_double(xyz[0]);
	y = str_to_double(xyz[1]);
	z = str_to_double(xyz[2]);
	if (is_point)
		return (point(x, y, z));
	else
		return (vector(x, y, z));
}
