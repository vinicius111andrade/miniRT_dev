/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:06:49 by vde-melo          #+#    #+#             */
/*   Updated: 2020/10/05 15:25:08 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>
#include <stdlib.h>

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_direction
{
	float		x;
	float		y;
	float		z;
}				t_direction;

typedef struct	s_vector
{
	t_point		origin;
	t_point		destin;
	t_direction	direction;
	float		magnitude;
}				t_vector;

float			vectorMagnitude(t_vector *vector);

#endif