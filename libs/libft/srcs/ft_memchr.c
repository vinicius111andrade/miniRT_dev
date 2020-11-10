/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:18:37 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:33 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	unsigned char			chr;

	ptr = s;
	chr = c;
	while (n > 0)
	{
		if (*ptr == chr)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (0);
}
