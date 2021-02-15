/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:11:35 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/15 21:35:16 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <stdlib.h>
# include "minirt.h"

void	test_parsing(t_scene *scene);
void	test_cam_parsing(t_scene *scene);
void	test_light_parsing(t_scene *scene);
void	test_plane_parsing(t_scene *scene);
void	test_sphere_parsing(t_scene *scene);
void	test_square_parsing(t_scene *scene);

#endif
