/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:15:07 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 18:44:55 by vde-melo         ###   ########.fr       */
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
		fatal_error_msg("046");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("047");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return tuple;
}

static void	validate_light(char **snippets, char **rgb)
{
	int			i;

	i = 0;
	if (is_number(snippets[2]) == 0)
		fatal_error_msg("041");
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("043");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("045");
		i++;
	}
}

static void	check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 4)
		fatal_error_msg("041");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("044");
}

void		parse_light(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_light		*light;
	t_colors	color;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[3], ',');
	check_arg_nb(snippets, rgb);
	validate_light(snippets, rgb);
	light = init_light();
	light->origin = get_and_check_xyz(snippets[1], 1);
	light->brightness = str_to_double(snippets[2]);
	if (is_ratio(light->brightness) == 0)
		fatal_error_msg("049");
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("048");
	light->color = color;
	link_light(scene, light);
	free_snippets(snippets, 4);
	free_snippets(rgb, 3);
}
