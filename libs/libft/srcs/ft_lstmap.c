/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:23:47 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:43 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*start;
	t_list	*element;

	start = 0;
	ptr = 0;
	if (!lst || !f)
		return (0);
	while (lst)
	{
		if (!(element = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			start = 0;
			return (0);
		}
		if (!start)
			start = element;
		else
			ptr->next = element;
		ptr = element;
		lst = lst->next;
	}
	return (start);
}
