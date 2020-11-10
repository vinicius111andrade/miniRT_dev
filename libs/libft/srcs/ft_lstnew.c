/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:49:07 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:41 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*element;

	if (!(element = (t_list *)ft_calloc(1, sizeof(t_list))))
		return (0);
	element->content = content;
	element->next = 0;
	return (element);
}
