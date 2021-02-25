/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:43:39 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/25 21:13:22 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	gen_mlx_img(t_rt *rt, t_cam *cam)
{
	if (!(cam->img.img = mlx_new_image(rt->mlx.mlx, rt->wd_res.x,
					 rt->wd_res.y)))
		fatal_error_msg("201");
	if (!(cam->img.addr = mlx_get_data_addr(cam->img.img, &cam->img.bpp,
					&cam->img.line_len, &cam->img.endian)))
		fatal_error_msg("201");
}

void		render_img(t_rt *rt)
{
	int		x;
	int		y;
	t_ray	ray;
	int		colour;
	t_cam	*cam;

	cam = rt->scene.cam;
	if (!cam)
		return ;
	gen_mlx_img(rt, cam);
	y = -1;
	while (y++ < (rt->wd_res.y - 1))
	{
		x = -1;
		while (x++ < (rt->wd_res.x - 1))
		{
			ray = gen_ray(cam, (float)x / rt->wd_res.x,
					(float)y / rt->wd_res.y);
			colour = raytrace(rt, &ray);
			mlx_put_pixel2img(&cam->img, x, (rt->wd_res.y - 1) - y, colour);
		}
	}
	if (rt->save == false)
		mlx_put_image_to_window(rt->mlx, rt->win, cam->img.ptr, 0, 0);
}
