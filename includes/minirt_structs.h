/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:58:11 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 19:25:23 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H

# include "minirt_dependencies.h"

/*
** IMAGE CREATION STRUCT
*/
typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

/*
** SCENE STRUCTS
*/
typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_amb_light
{
	double			brightness;
	t_colors		color;
}					t_amb_light;

typedef struct		s_cam
{
	t_tuples		origin;
	t_tuples		direction;
	double			fov;
	t_tuples		hor;
	t_tuples		ver;
	t_tuples		llc;
	t_img			img;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_tuples		origin;
	double			brightness;
	t_colors		color;
	struct s_light	*next;
}					t_light;

typedef struct		s_pl
{
	t_tuples		origin;
	t_tuples		normal;
	t_colors		color;
	struct s_pl		*next;
}					t_pl;

typedef struct		s_sp
{
	t_tuples		origin;
	double			diameter;
	t_colors		color;
	struct s_sp		*next;
}					t_sp;

typedef struct		s_sq
{
	t_tuples		origin;
	t_tuples		normal;
	double			side;
	t_colors		color;
	struct s_sq		*next;
}					t_sq;

typedef struct		s_cy
{
	t_tuples		origin;
	t_tuples		normal;
	double			diameter;
	double			height;
	t_colors		color;
	struct s_cy		*next;
}					t_cy;

typedef struct		s_tr
{
	t_tuples		p1;
	t_tuples		p2;
	t_tuples		p3;
	t_colors		color;
	struct s_tr		*next;
}					t_tr;

typedef struct		s_scene
{
	char			*line;
	int				has_res;
	int				has_ambl;
	int				has_cam;
	t_res			*res;
	t_amb_light		*amb_light;
	t_cam			*cam;
	t_light			*light;
	t_pl			*pl;
	t_sp			*sp;
	t_sq			*sq;
	t_cy			*cy;
	t_tr			*tr;
}					t_scene;

/*
** MLX STRUCT
*/
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

/*
** RAYTRACING STRUCTS
*/
typedef struct	s_hit
{
	double		time;
	t_tuples	point;
	t_tuples	normal;
	t_colors		color;
	void		*obj;
}				t_hit;

typedef struct	s_ray
{
	t_tuples	origin;
	t_tuples	direction;
	t_hit		hit;
}				t_ray;

/*
** GLOBAL STRUCT
*/
typedef struct	s_rt
{
	int			save;
	t_res		wd_res;
	t_img		img;
	t_scene		scene;
	t_mlx		mlx;
}				t_rt;

#endif
