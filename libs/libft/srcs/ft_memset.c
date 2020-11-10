/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:11:00 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:27 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	char	*ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}
