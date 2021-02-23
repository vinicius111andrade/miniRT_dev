/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:10:03 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:19:06 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void		*new_window(t_rt *rt)
// {
// 	mlx_new_window(mlx, 1920, 1080, "Hello world!");
// }

void		start_mlx(t_rt *rt)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	rt->mlx.mlx = mlx;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//mlx_win = new_window(&rt);
	mlx_loop(mlx);
}
