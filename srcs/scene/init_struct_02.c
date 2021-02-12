/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:08:28 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 22:54:25 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_sp		*init_sp(void)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	*sp = (t_sp) {{0}, 0, {0}, 0};
	return (sp);
}

t_sq		*init_sq(void)
{
	t_sq	*sq;

	sq = malloc(sizeof(t_sq));
	*sq = (t_sq) {{0}, {0}, 0, {0}, 0};
	return (sq);
}

t_cy		*init_cy(void)
{
	t_cy	*cy;

	cy = malloc(sizeof(t_cy));
	*cy = (t_cy) {{0}, {0}, 0, 0, {0}, 0};
	return (cy);
}

// t_tr		*init_tr(void)
// {
// 	t_tr	*tr;

// 	tr = malloc(sizeof(t_tr));
// 	*tr = (t_tr) {{0}, {0}, {0}, {0}, 0};
// 	return (tr);
// }

t_tr		*init_tr(void)
{
	return ft_calloc(1, sizeof(t_tr));
}
