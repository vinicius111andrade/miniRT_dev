/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:07:09 by vde-melo          #+#    #+#             */
/*   Updated: 2020/10/09 17:26:32 by vde-melo         ###   ########.fr       */
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