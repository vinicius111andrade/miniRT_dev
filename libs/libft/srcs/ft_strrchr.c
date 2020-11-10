/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:43:02 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:32:29 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				len;
	char			*str;

	chr = c;
	len = 1;
	str = (char *)s;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	while (len > 0)
	{
		if (*str == chr)
			return (str);
		str--;
		len--;
	}
	return (0);
}
