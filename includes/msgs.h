/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:57:42 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/08 20:00:27 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "libft.h"
# include <fcntl.h>

void		msg(char *id);
void		error_msg(char *id);
void		fatal_error_msg(char *error_msg);

#endif
