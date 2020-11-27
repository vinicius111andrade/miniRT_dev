/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:06:14 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 20:58:50 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (0);
		*substr = 0;
		return (substr);
	}
	if (!(substr = (char *)ft_calloc((len + 1), sizeof(char))))
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = ((char *)s)[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
