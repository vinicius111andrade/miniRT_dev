/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 23:23:43 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:30:29 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int			validate_line_chars(char *str)
{
	int		i;

	i = 0;
	while (str[i])
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
