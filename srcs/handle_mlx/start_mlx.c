/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:10:03 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 21:20:23 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		start_mlx(t_rt *rt)
{
	rt->mlx.mlx = mlx_init();
	rt->mlx.win = mlx_new_window(rt->mlx.mlx, rt->scene.res->x, rt->scene.res->y,
	 "-- MiniRT --");
	mlx_loop(rt->mlx.mlx);
}
