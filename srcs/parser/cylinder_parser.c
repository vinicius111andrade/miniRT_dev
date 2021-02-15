/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:41:35 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 21:57:45 by vde-melo         ###   ########.fr       */
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
		fatal_error_msg("085");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("086");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return tuple;
}

static void	validate_cylinder_color(char **rgb)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("082");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("084");
		i++;
	}
}

static void	validate_diameter_n_height(char *diameter, char *height)
{
	if (is_number(diameter) == 0)
		fatal_error_msg("081");
	if (is_number(height) == 0)
		fatal_error_msg("090");
}

static void	check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 6)
		fatal_error_msg("080");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("083");
}

static void validate_normal(t_tuples normal)
{
	if (normal.x < -1.0 || normal.x > 1.0)
		fatal_error_msg("079");
	else if (normal.y < -1.0 || normal.y > 1.0)
		fatal_error_msg("079");
	else if (normal.z < -1.0 || normal.z > 1.0)
		fatal_error_msg("079");
}

void		parse_cylinder(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_cy		*cylinder;
	t_colors	color;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[5], ',');
	check_arg_nb(snippets, rgb);
	validate_cylinder_color(rgb);
	validate_diameter_n_height(snippets[3], snippets[4]);
	cylinder = init_cy();
	cylinder->origin = get_and_check_xyz(snippets[1], 1);
	cylinder->normal = get_and_check_xyz(snippets[2], 0);
	validate_normal(cylinder->normal);
	cylinder->diameter = str_to_double(snippets[3]);
	if (cylinder->diameter <= 0.0)
		fatal_error_msg("087");
	cylinder->height = str_to_double(snippets[4]);
	if (cylinder->height <= 0.0)
		fatal_error_msg("091");
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("088");
	cylinder->color = color;
	link_cylinder(scene, cylinder);
	free_snippets(snippets, 6);
	free_snippets(rgb, 3);
}
