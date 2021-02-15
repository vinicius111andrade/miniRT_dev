/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:43:19 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 21:31:46 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "colors.h"
# include "tuples.h"
# include "libft.h"

/*
** Scene elements defined in .rt
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

/*
** Scene definition
*/
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

t_res				*init_res(void);
t_amb_light			*init_amb_light(void);
t_cam				*init_cam(void);
t_light				*init_light(void);
t_pl				*init_pl(void);
t_sp				*init_sp(void);
t_sq				*init_sq(void);
t_cy				*init_cy(void);
t_tr				*init_tr(void);
void				link_cam(t_scene *scene, t_cam *new_cam);
void				link_light(t_scene *scene, t_light *new_light);
void				link_plane(t_scene *scene, t_pl *new_plane);
void				link_sphere(t_scene *scene, t_sp *new_sphere);
void				link_square(t_scene *scene, t_sq *new_square);

#endif
