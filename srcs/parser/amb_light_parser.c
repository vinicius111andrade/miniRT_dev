/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_light_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:40:34 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:29:23 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** checar se eh num e se eh ratio
** checar se RGB eh positivo
*/

static void	validate_amb_light(char **snippets, char **rgb)
{
	int			i;

	i = 0;
	if (is_number(snippets[1]) == 0)
		fatal_error_msg("027");
	while (i < 3)
	{
		if (is_number(rgb[i]) == 0 || is_int(rgb[i]) == 0)
			fatal_error_msg("030");
		else if (nonnegative_str_nb(rgb[i]) == 0)
			fatal_error_msg("032");
		i++;
	}
}

static void	check_arg_nb(char **snippets, char **rgb)
{
	if (count_snippets(snippets) != 3)
		fatal_error_msg("029");
	if (count_snippets(rgb) != 3)
		fatal_error_msg("031");
}

void		parse_amb_light(t_scene *scene)
{
	char		**snippets;
	char		**rgb;
	t_amb_light	*amb_light;
	t_colors	color;

	if (scene->has_ambl == 1)
		fatal_error_msg("028");
	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	rgb = ft_split(snippets[2], ',');
	check_arg_nb(snippets, rgb);
	validate_amb_light(snippets, rgb);
	get_rgb(rgb, &color);
	if (validate_rgb_bounds(color) == 0)
		fatal_error_msg("033");
	amb_light = init_amb_light();
	amb_light->brightness = str_to_double(snippets[1]);
	if (is_ratio(amb_light->brightness) == 0)
		fatal_error_msg("034");
	amb_light->color = color;
	scene->amb_light = amb_light;
	scene->has_ambl = 1;
	free_snippets(rgb, 3);
	free_snippets(snippets, 3);
}
