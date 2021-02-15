/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:50:13 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 20:43:16 by vde-melo         ###   ########.fr       */
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
		fatal_error_msg("055");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("056");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return tuple;
}

static void	validate_plane_color(char **rgb)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("052");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("054");
		i++;
	}
}

static void	check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 4)
		fatal_error_msg("050");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("053");
}

static void validate_normal(t_tuples normal)
{
	if (normal.x < -1.0 || normal.x > 1.0)
		fatal_error_msg("057");
	else if (normal.y < -1.0 || normal.y > 1.0)
		fatal_error_msg("057");
	else if (normal.z < -1.0 || normal.z > 1.0)
		fatal_error_msg("057");
}

void		parse_plane(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_pl		*plane;
	t_colors	color;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[3], ',');
	check_arg_nb(snippets, rgb);
	validate_plane_color(rgb);
	plane = init_pl();
	plane->origin = get_and_check_xyz(snippets[1], 1);
	plane->normal = get_and_check_xyz(snippets[2], 0);
	validate_normal(plane->normal);
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("058");
	plane->color = color;
	link_plane(scene, plane);
	free_snippets(snippets, 4);
	free_snippets(rgb, 3);
}
