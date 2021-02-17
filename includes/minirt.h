/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:47:49 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/17 21:15:40 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** Headers
*/
# include "scene.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "libft.h"
# include "colors.h"
# include "tuples.h"
# include "msgs.h"
# include "parser.h"
# include "handle_mlx.h"
# include "tests.h" //tirar depois, tirar da pasta includes tbm

# define EPSILON 0.00001

/*
** Structs
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
	t_rt		*rt;
}				t_mlx;

typedef struct	s_rt
{
	int			save;
	int			size_x;
	int			size_y;
	t_img		img;
	t_scene		scene;
	t_mlx		mlx_info;
}				t_rt;

#endif
