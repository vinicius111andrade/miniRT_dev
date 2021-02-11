/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:34:05 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/11 21:15:55 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include <fcntl.h>

int		reversed_strncmp(const char *s1, const char *s2, size_t n);
int		validate_line_chars(char *str);
int		is_int(char *str);
int		is_number(char *str);
double	str_to_double(char *str);
int		count_snippets(char **line_snippets);
void	parse_file(char *file, t_scene *scene);
void	parse_line(int id_nb, t_scene *scene);
void	parse_res(t_scene *scene);
void	free_snippets(char **snippets, int nb);

#endif