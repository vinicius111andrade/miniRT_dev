/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:08:28 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 16:51:14 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_sp		*init_sp(void)
{
	t_sp	*sp;

	sp = ft_calloc(1, sizeof(t_sp));
	sp->next = NULL;
	return (sp);
}

t_sq		*init_sq(void)
{
	t_sq	*sq;

	sq = ft_calloc(1, sizeof(t_sq));
	sq->next = NULL;
	return (sq);
}

t_cy		*init_cy(void)
{
	t_cy	*cy;

	cy = ft_calloc(1, sizeof(t_cy));
	cy->next = NULL;
	return (cy);
}

t_tr		*init_tr(void)
{
	t_tr	*tr;

	tr = ft_calloc(1, sizeof(t_tr));
	tr->next = NULL;
	return (tr);
}
