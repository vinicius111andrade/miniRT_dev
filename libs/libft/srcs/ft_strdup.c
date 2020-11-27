/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:32:26 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 20:34:31 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strdup(const char *s1)
{
	int		s_len;
	char	*new_s;

	s_len = ft_strlen(s1);
	if (!(new_s = malloc((s_len + 1) * sizeof(char))))
		return (0);
	while (s_len >= 0)
	{
		new_s[s_len] = (char)s1[s_len];
		s_len--;
	}
	return (new_s);
}
