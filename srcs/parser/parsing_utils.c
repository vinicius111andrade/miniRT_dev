/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:42:37 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/09 19:07:19 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	reversed_strncmp(const char *s1, const char *s2, size_t n)
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
