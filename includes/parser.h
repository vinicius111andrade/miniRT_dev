/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:34:05 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/09 19:44:15 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include <fcntl.h>

int		reversed_strncmp(const char *s1, const char *s2, size_t n);
void	parse_file(char *file, t_scene *scene);
void	parse_line(int id_nb, t_scene *scene);

#endif
