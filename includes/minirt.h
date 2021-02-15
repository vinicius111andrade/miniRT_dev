/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:47:49 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 22:52:29 by vde-melo         ###   ########.fr       */
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
# include "tests.h" //tirar depois, tirar da pasta includes tbm

/*
** Structs
*/
typedef struct	s_rt
{
	int			save;
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	t_img		img;
	t_scene		scene;
}				t_rt;

#endif
