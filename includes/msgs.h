/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:57:42 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/08 22:03:46 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS_H
# define MSGS_H

# include "libft.h"
# include <fcntl.h>

void		msg(char *id);
void		error_msg(char *id);
void		fatal_error_msg(char *error_msg);

#endif
