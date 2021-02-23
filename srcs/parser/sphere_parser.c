/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 20:52:05 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:30:01 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuples	get_and_check_xyz(char *coord, int is_point)
{
	char		**xyz;
	int			i;
	t_tuples	tuple;

	xyz = ft_split(coord, ',');
	if (count_snippets(xyz) != 3)
		fatal_error_msg("065");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("066");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return (tuple);
}

static void		validate_sphere_color(char **rgb)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("062");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("064");
		i++;
	}
}

static void		validate_diameter(char *diameter_str)
{
	if (is_number(diameter_str) == 0)
		fatal_error_msg("061");
}

static void		check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 4)
		fatal_error_msg("060");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("063");
}

void			parse_sphere(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_sp		*sphere;
	t_colors	color;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[3], ',');
	check_arg_nb(snippets, rgb);
	validate_sphere_color(rgb);
	validate_diameter(snippets[2]);
	sphere = init_sp();
	sphere->origin = get_and_check_xyz(snippets[1], 1);
	sphere->diameter = str_to_double(snippets[2]);
	if (sphere->diameter <= 0.0)
		fatal_error_msg("067");
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("068");
	sphere->color = color;
	link_sphere(scene, sphere);
	free_snippets(snippets, 4);
	free_snippets(rgb, 3);
}
