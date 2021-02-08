/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:57:50 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/05 21:03:06 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void		error_msg(char *id)
{
	int		fd;
	char	*error_msg;

	if ((fd = open("srcs/erros/errors.txt", O_RDONLY)) < 0)
		fatal_error_msg("Could not read errors.txt");

	error_msg = "oh no! we have an error!!";
	ft_putstr_fd("\033[1m\033[0;31;199mERROR ID: \033[0m", STDERR_FILENO);
	ft_putstr_fd(id, STDERR_FILENO);
	ft_putstr_fd(" \033[1m\033[1;36;199mMSG: \033[0m", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void		fatal_error_msg(char *error_msg)
{
	ft_putstr_fd("\033[1m\033[0;31;199mFATAL ERROR ID: \033[0m", STDERR_FILENO);
	ft_putstr_fd("FATAL", STDERR_FILENO);
	ft_putstr_fd(" \033[1m\033[0;31;199mMSG: \033[0m", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
