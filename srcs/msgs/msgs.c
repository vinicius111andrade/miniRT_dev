/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:57:50 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/23 20:29:12 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		msg(char *id)
{
	int		fd;
	char	*msg;

	if ((fd = open("srcs/msgs/msgs.txt", O_RDONLY)) < 0)
		fatal_error_msg("could not read txt");
	while (get_next_line(fd, &msg) == 1)
	{
		if (ft_strncmp(id, msg, 3) == 0)
		{
			ft_putstr_fd("\033[1m\033[1;36;199mMSG: \033[0m", STDERR_FILENO);
			ft_putstr_fd(msg, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			break ;
		}
		free(msg);
	}
	free(msg);
	close(fd);
}

void		error_msg(char *id)
{
	ft_putstr_fd("\033[1m\033[0;31;199mERROR \033[0m", STDERR_FILENO);
	msg(id);
}

void		fatal_error_msg(char *id)
{
	ft_putstr_fd("\033[1m\033[0;31;199mFATAL \033[0m", STDERR_FILENO);
	if (ft_strncmp(id, "could not read txt", 19) == 0)
		ft_putstr_fd("Could not read errors.txt", STDERR_FILENO);
	else
		error_msg(id);
	exit(EXIT_FAILURE);
}
