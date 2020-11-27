/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:04:35 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 20:38:08 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		new_len;
	char	*newstr;
	int		i;

	if (!s1 || !s2)
		return (0);
	new_len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((new_len + 1) * sizeof(*newstr));
	if (newstr == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
