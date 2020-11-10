/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:36:55 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:07 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	char			*str;

	chr = c;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (0);
}
