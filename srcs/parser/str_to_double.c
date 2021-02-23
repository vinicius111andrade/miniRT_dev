/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 23:25:31 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:31:24 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	add_decimal_part(int i, double number, char *str)
{
	double	decimal_depth;

	decimal_depth = 1;
	while (str[i] > 47 && str[i] < 58)
	{
		decimal_depth /= 10;
		number += ((str[i++] - 48) * decimal_depth);
	}
	return (number);
}

double			str_to_double(char *str)
{
	double	sign;
	int		i;
	double	number;

	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i] != '.')
	{
		number *= 10;
		number += str[i++] - 48;
	}
	if (str[i] == '.')
		i++;
	number = add_decimal_part(i, number, str);
	return (number * sign);
}
