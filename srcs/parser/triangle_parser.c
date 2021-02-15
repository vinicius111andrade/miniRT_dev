/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:01:59 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 22:14:28 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_tuples	get_and_check_xyz(char *coord, int is_point)
{
	char		**xyz;
	int			i;
	t_tuples	tuple;

	xyz = ft_split(coord, ',');
	if (count_snippets(xyz) != 3)
		fatal_error_msg("096");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("097");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return tuple;
}

static void	validate_triangle_color(char **rgb)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("093");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("095");
		i++;
	}
}

static void	check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 5)
		fatal_error_msg("092");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("093");
}

void		parse_triangle(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_tr		*triangle;
	t_colors	color;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[4], ',');
	check_arg_nb(snippets, rgb);
	validate_triangle_color(rgb);
	triangle = init_tr();
	triangle->p1 = get_and_check_xyz(snippets[1], 1);
	triangle->p2 = get_and_check_xyz(snippets[2], 1);
	triangle->p3 = get_and_check_xyz(snippets[3], 1);
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("088");
	triangle->color = color;
	link_triangle(scene, triangle);
	free_snippets(snippets, 5);
	free_snippets(rgb, 3);
}
