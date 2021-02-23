/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:42:37 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:30:34 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			is_valid_char(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '-') || (c == '+') || (c == '.') ||
		(c == ',') || (c == ' ') || (c == '\n'))
		return (1);
	return (0);
}

static int	only_nb_chars(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if ((c > 47 && c < 58) || c == '+' || c == '-' || c == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	only_one_decimal_sep(char *str)
{
	int		i;
	int		point_counter;
	char	c;

	i = 0;
	point_counter = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '.')
			point_counter++;
		i++;
	}
	if (point_counter == 0 || point_counter == 1)
		return (1);
	else
		return (0);
}

static int	clean_number(char *str)
{
	int		i;
	char	c;

	i = 1;
	while (str[i])
	{
		c = str[i];
		if (c == '+' || c == '-')
			return (0);
		i++;
	}
	return (1);
}

int			is_number(char *str)
{
	if (only_nb_chars(str) == 0 || only_one_decimal_sep(str) == 0)
		return (0);
	else if (clean_number(str) == 0)
		return (0);
	else
		return (1);
}
