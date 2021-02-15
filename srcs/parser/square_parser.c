/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:14:28 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 23:20:43 by vde-melo         ###   ########.fr       */
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
		fatal_error_msg("075");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("076");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return (tuple);
}

static void		validate_some_square_arguments(char **rgb, t_sq *square)
{
	int			i;
	t_tuples	normal;

	i = 0;
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("072");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("074");
		i++;
	}
	normal = square->normal;
	if (normal.x < -1.0 || normal.x > 1.0)
		fatal_error_msg("079");
	else if (normal.y < -1.0 || normal.y > 1.0)
		fatal_error_msg("079");
	else if (normal.z < -1.0 || normal.z > 1.0)
		fatal_error_msg("079");
	if (square->side <= 0.0)
		fatal_error_msg("077");
}

static void		validate_side_size(char *side_str)
{
	if (is_number(side_str) == 0)
		fatal_error_msg("071");
}

static void		check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 5)
		fatal_error_msg("070");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("073");
}

void			parse_square(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_sq		*square;
	t_colors	color;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[4], ',');
	check_arg_nb(snippets, rgb);
	validate_side_size(snippets[3]);
	square = init_sq();
	square->origin = get_and_check_xyz(snippets[1], 1);
	square->normal = get_and_check_xyz(snippets[2], 0);
	square->side = str_to_double(snippets[3]);
	validate_some_square_arguments(rgb, square);
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("078");
	square->color = color;
	link_square(scene, square);
	free_snippets(snippets, 5);
	free_snippets(rgb, 3);
}
