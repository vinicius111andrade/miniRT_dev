/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:24:56 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/25 15:09:30 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** tem q achar apenas dois numeros inteiros maiores q zero na str
** primeiro x, depois y
**
** pula os dois primeiros chars, vai andando ateh encontrar algo q n seja
** espaco, achou algo q n eh espaco pergunta o q eh e se eh char valido,
** se for char valido comeca a armazenar a string ateh n ser mais valido
** ou espaco, procura o proximo valor, terminou? checa se n tem mais nada
** na str alem de espaco
**
** usar split??
**
** checa se os valores passados sao validos, se n forem: FATAL ERROR NELES
**
** malloc no scene->line, scene->snippets, no scene->res
*/

static void	validate_res(char **snippets)
{
	int		i;

	i = 1;
	while (i < 3)
	{
		if (is_number(snippets[i]) == 0 || is_int(snippets[i]) == 0)
			fatal_error_msg("024");
		i++;
	}
}

void		parse_res(t_scene *scene)
{
	char	**snippets;
	t_res	*res;

	if (scene->has_res == 1)
		fatal_error_msg("025");
	validate_line_chars(scene->line);
	snippets = ft_split(scene->line, ' ');
	if (count_snippets(snippets) != 3)
		fatal_error_msg("022");
	validate_res(snippets);
	res = init_res();
	res->x = ft_atoi(snippets[1]);
	res->y = ft_atoi(snippets[2]);
	if (res->x < 1 || res->y < 1)
		fatal_error_msg("026");
	scene->res = res;
	scene->has_res = 1;
	free_snippets(snippets, 3);
}
