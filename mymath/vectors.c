/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:19:13 by vde-melo          #+#    #+#             */
/*   Updated: 2020/10/05 16:54:40 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

float		vectorMagnitude(t_vector *vector)
{
	float		magnitude;
	float		delta_x;
	float		delta_y;
	float		delta_z;

	delta_x = vector->destin - vector.origin.x;
	delta_y = vector.destin.y - vector.origin.y;
	delta_z = vector.destin.z - vector.origin.z;
	magnitude = sqrt(pow(delta_x, 2) + pow(delta_y, 2) + pow(delta_z, 2));

	return magnitude;
}

//t_direction	*vectorDirection(t_vector *vector)