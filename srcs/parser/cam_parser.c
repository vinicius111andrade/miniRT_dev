/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:37:35 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 18:13:03 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** origem, direcao, fov
** checar se origem eh ponto
** e se direcao eh vetor com x,y,z entre -1 e 1
** checar se fov esta entre 0 e 180
** colocar na linked list corretamente
*/

static void	validate_fov(char **snippets)
{
	if (is_number(snippets[3]) == 0)
		fatal_error_msg("036");
}

static void	check_arg_nb(char **snippets)
{
	if (count_snippets(snippets) != 4)
		fatal_error_msg("035");
}

static t_tuples	get_and_check_xyz(char *coord, int is_point)
{
	char		**xyz;
	int			i;
	t_tuples	tuple;

	xyz = ft_split(coord, ',');
	if (count_snippets(xyz) != 3)
		fatal_error_msg("037");
	i = 0;
	while (i < 3)
	{
		if (is_number(xyz[i]) == 0)
			fatal_error_msg("038");
		i++;
	}
	tuple = str_to_tuple(xyz, is_point);
	free_snippets(xyz, 3);
	return tuple;
}

static void	validate_direction(t_tuples direction)
{
	if (direction.x < -1.0 || direction.x > 1.0)
		fatal_error_msg("039");
	else if (direction.y < -1.0 || direction.y > 1.0)
		fatal_error_msg("039");
	else if (direction.z < -1.0 || direction.z > 1.0)
		fatal_error_msg("039");
}

void		parse_cam(t_scene *scene)
{
	char		**snippets;
	char		**xyz;
	t_cam		*cam;
	t_tuples	tuple;

	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	check_arg_nb(snippets);
	validate_fov(snippets);
	cam = init_cam();
	tuple = get_and_check_xyz(snippets[1], 1);
	cam->origin = tuple;
	tuple = get_and_check_xyz(snippets[2], 0);
	cam->direction = tuple;
	validate_direction(cam->direction);
	cam->fov = str_to_double(snippets[3]);
	if (validate_fov_bounds(cam->fov) == 0)
		fatal_error_msg("033");
	link_cam(scene, cam);
	scene->has_cam = 1;
	free_snippets(snippets, 3);
}
