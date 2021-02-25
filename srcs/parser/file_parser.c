/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:28:48 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/25 15:33:03 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** le linha a linha
** se acha um id ou ## ou \n ele n reclama
** se n achar nada disso ele diz q o .rt eh invalido
** achando o id ele manda pra uma outra funcao a linha, o id, e o scene
*/

static void	validate_rt_file_name(char *file)
{
	int i;

	i = 0;
	if (file[i] == '.')
		i++;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'r' && file[i + 2] == 't'
				&& file[i + 3] == '\0')
				return ;
			else
				fatal_error_msg("015");
		}
		i++;
	}
	fatal_error_msg("015");
}

void		parse_file(char *file, t_scene *scene)
{
	static char		*id[11] = {"R ", "A ", "c ", "l ",
								"sp", "pl", "sq", "cy", "tr", "##", "# "};
	int				id_nb;
	int				fd;

	validate_rt_file_name(file);
	if ((fd = open(file, O_RDONLY)) < 0)
		fatal_error_msg("001");
	ft_bzero(scene, sizeof(t_scene));
	while (get_next_line(fd, &scene->line) == 1)
	{
		id_nb = 0;
		while (id_nb < 11 && ft_strncmp(scene->line, id[id_nb], 2))
			id_nb++;
		if (id_nb == 11 && ft_strncmp(scene->line, "\0", 1))
			fatal_error_msg("020");
		if (id_nb < 9)
			parse_line(id_nb, scene);
		free(scene->line);
	}
	close(fd);
	if (scene->has_res == 0 || scene->has_cam == 0)
		fatal_error_msg("023");
	msg("110");
}
