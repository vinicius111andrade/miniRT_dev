/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:10:03 by vde-melo          #+#    #+#             */
/*   Updated: 2021/03/02 15:43:48 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		get_rendering_res(t_rt *rt)
{
	t_res		screen;

	if (rt->save == 0)
	{
		mlx_get_screen_size(rt->mlx.mlx, &screen.x, &screen.y);
		if (rt->scene.res->x < screen.x)
			rt->wd_res.x = rt->scene.res->x;
		else
			rt->wd_res.x = screen.x;
		if (rt->scene.res->y < screen.y)
			rt->wd_res.y = rt->scene.res->y;
		else
			rt->wd_res.y = screen.y;
		rt->mlx.win = mlx_new_window(rt->mlx.mlx, rt->wd_res.x, rt->wd_res.y,
	 "-- MiniRT --");
	 	msg("111");
	}
	else
	{
		rt->wd_res.x = rt->scene.res->x;
		rt->wd_res.y = rt->scene.res->y;
		rt->mlx.win = NULL;
		msg("112");
	}
}

void			start_mlx(t_rt *rt)
{
	if (!(rt->mlx.mlx = mlx_init()))
		fatal_error_msg("200");
	get_rendering_res(rt);
}
