/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector_and_point.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:08:25 by vde-melo          #+#    #+#             */
/*   Updated: 2020/10/07 18:13:59 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

t_point		*create_point(float x, float y, float z)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
}

t_vector	*create_vector(t_point *origin, t_point *destin)
	t_vector	*vector;

	vector = malloc(sizeof(t_vector))