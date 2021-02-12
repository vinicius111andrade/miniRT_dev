/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:42:37 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/12 17:55:46 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			reversed_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (s1[--i] == s2[--j] && i >= 0 && j >= 0)
	{
		n--;
		if (n == 0)
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}

static int	is_valid_char(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '-') || (c == '+') || (c == '.') ||
		(c == ',') || (c == ' ') || (c == '\n'))
		return (1);
	return (0);
}

int			validate_line_chars(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (is_valid_char(str[i]) == 0)
			fatal_error_msg("021");
		i++;
	}
	return (0);
}

int			count_snippets(char **line_snippets)
{
	int		nb;

	nb = 0;
	while (line_snippets[nb])
		nb++;
	return (nb);
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

int			is_int(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if ((c > 47 && c < 58) || c == '+' || c == '-')
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

int		is_number(char *str)
{
	if (only_nb_chars(str) == 0 || only_one_decimal_sep(str) == 0)
		return (0);
	else if (clean_number(str) == 0)
		return (0);
	else
		return (1);
}

double	str_to_double(char *str)
{
	double	sign;
	int		i;
	double	number;
	double	decimal_depth;

	number = 0;
	sign = 1;
	i = 0;
	decimal_depth = 1;
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
		while (str[i] > 47 && str[i] < 58)
	{
		decimal_depth /= 10;
		number += ((str[i++] - 48) * decimal_depth);
	}
	return (number * sign);
}

void		free_snippets(char **snippets, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		free(snippets[i]);
		i++;
	}
	free(snippets);
}

int			nonnegative_str_nb(char *str)
{
	if (str[0] == '-')
		return (0);
	return (1);
}

int			is_ratio(double n)
{
	if (n >= 0.0 && n <= 1.0)
		return (1);
	else
		return (0);
}

void		get_rgb(char **rgb, t_colors *color)
{
	color->a = 255;
	color->r = str_to_double(rgb[0]);
	color->b = str_to_double(rgb[1]);
	color->g = str_to_double(rgb[2]);
}

int			validate_rgb_bounds(t_colors color)
{
	if (color.a < 0 || color.a > 255)
		return (0);
	else if (color.r < 0 || color.r > 255)
		return (0);
	else if (color.g < 0 || color.g > 255)
		return (0);
	else if (color.b < 0 || color.b > 255)
		return (0);
	return (1);
}

t_tuples	str_to_tuple(char **xyz, int is_point)
{
	double	x;
	double	y;
	double	z;

	x = str_to_double(xyz[0]);
	y = str_to_double(xyz[1]);
	z = str_to_double(xyz[2]);
	if (is_point)
		return point(x, y, z);
	else
		return vector(x, y, z);
}
