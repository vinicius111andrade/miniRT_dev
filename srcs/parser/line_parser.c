/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:37:01 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/11 20:53:46 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** chama a funcao certa pra ler a linha de acordo com o id_nb
*/
void	parse_line(int id_nb, t_scene *scene)
{
	if (id_nb == 0)
	{
		msg("990");
		parse_res(scene);
	}
	else if (id_nb == 1)
		msg("991");
	else if (id_nb == 2)
		msg("992");
	else if (id_nb == 3)
		msg("993");
	else if (id_nb == 4)
		msg("994");
	else if (id_nb == 5)
		msg("995");
	else if (id_nb == 6)
		msg("996");
	else if (id_nb == 7)
		msg("997");
	else if (id_nb == 8)
		msg("998");
	scene = 0;
}
