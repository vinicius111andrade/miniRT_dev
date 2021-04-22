/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:47:49 by vde-melo          #+#    #+#             */
/*   Updated: 2021/04/22 21:42:18 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** MiniRT
**
** minirt.h -> functions.h -> structs.h -> dependencies.h
*/
# include "minirt_functions.h"
/*
** MiniRT Test
*/
# include "tests.h" //tirar depois, tirar da pasta includes tbm
# include <stdio.h>

/*
** Constants
*/
# define EPSILON	0.00001
# define PI_L12		3.14159265359
# define ALBEDO		1000

#endif
