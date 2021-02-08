/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:43:19 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/08 23:17:50 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

/*
** Scene definition
*/
typedef struct		s_scene
{
	t_res			res;
	t_amb_light		amb_light;
	t_cam			*cam;
	t_light			*light;
	t_pl			*pl;
	t_sp			*sp;
	t_sq			*sq;
	t_cy			*cy;
	t_tr			*tr;
}					t_scene;

/*
** Scene elements defined in .rt
*/
typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_amb_light
{
	float			brightness;
	t_colors		color;
}					t_amb_light;

typedef struct		s_cam
{
	t_tuples		origin;
	t_tuples		direction;
	float			fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_tuples		origin;
	float			brightness;
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
	float			diameter;
	t_colors		color;
	struct s_sp		*next;
}					t_sp;

typedef struct		s_sq
{
	t_tuples		origin;
	t_tuples		normal;
	float			side;
	t_colors		color;
	struct s_sq		*next;
}					t_sq;

typedef struct		s_cy
{
	t_tuples		origin;
	t_tuples		normal;
	float			diameter;
	float			height;
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

#endif
