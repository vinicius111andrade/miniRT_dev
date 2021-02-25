/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:58:11 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/25 14:38:56 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H

# include "minirt_dependencies.h"

/*
** SCENE STRUCTS
*/
typedef struct		s_res
{
	double				x;
	double				y;
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
	t_cam		*cam;
	t_cam		*begin;
	int			bpp;
	int			line_leng;
	int			endian;
}				t_mlx;

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
