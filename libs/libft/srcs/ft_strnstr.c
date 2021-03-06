/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:21:28 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 21:08:56 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while ((haystack[i + j] == needle[j]) && (i + j) < len &&
			needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
			{
				haystack = &haystack[i];
				return ((char*)haystack);
			}
		}
		i++;
	}
	return (0);
}
