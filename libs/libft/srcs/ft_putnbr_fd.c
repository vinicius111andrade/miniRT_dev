/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:38:40 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:17 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	long_n;

	long_n = n;
	if (long_n < 0)
	{
		long_n = -long_n;
		ft_putchar_fd('-', fd);
	}
	if (long_n < 10)
		ft_putchar_fd(long_n + '0', fd);
	else
	{
		ft_putnbr_fd(long_n / 10, fd);
		ft_putnbr_fd(long_n % 10, fd);
	}
}
