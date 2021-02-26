/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:43:39 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 22:48:16 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	gen_cam_render_info(t_scene *scene, t_cam *cam)
{
	double		vp[2];
	t_tuples	w;
	t_tuples	u;
	t_tuples	v;

	while (cam)
	{
		vp[0] = 2 * tan(cam->fov / 2);
		vp[1] = vp[0] * (double)scene->res->y / scene->res->x;
		w = normalize(neg_tuples(cam->direction));
		u = crossproduct(vector(0, 1, 0), w);
		v = crossproduct(w, u);
		cam->hor = scale_tuples(vp[0], u);
		cam->ver = scale_tuples(vp[1], v);
		cam->llc = sub_tuples(cam->origin, scale_tuples(0.5, cam->hor));
		cam->llc = sub_tuples(cam->llc, scale_tuples(0.5, cam->ver));
		cam->llc = sub_tuples(cam->llc, w);
		cam = cam->next;
	}
}

static void	gen_extra_cam_info(t_rt *rt, t_cam *cam)
{
	if (!(cam->img.img = mlx_new_image(rt->mlx.mlx, rt->wd_res.x,
					 rt->wd_res.y)))
		fatal_error_msg("201");
	if (!(cam->img.addr = mlx_get_data_addr(cam->img.img, &cam->img.bpp,
					&cam->img.line_len, &cam->img.endian)))
		fatal_error_msg("201");
	gen_cam_render_info(&rt->scene, cam);
}

void		render_img(t_rt *rt)
{
	int		x;
	int		y;
	t_ray	ray;
	int		color_bin;
	t_cam	*cam;

	cam = rt->scene.cam;
	if (!cam)
		return ;
	gen_extra_cam_info(rt, cam);
	y = -1;
	while (y++ < (rt->wd_res.y - 1))
	{
		x = -1;
		while (x++ < (rt->wd_res.x - 1))
		{
			ray = gen_ray(cam, (double)x / rt->wd_res.x,
					(double)y / rt->wd_res.y);
			color_bin = raytrace(rt, &ray);
			mlx_put_pixel2img(&cam->img, x, (rt->wd_res.y - 1) - y, color_bin);
		}
	}
	if (rt->save == 0)
		mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win, cam->img.img, 0, 0);
}
