/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:01:21 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/26 22:33:46 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

# include "minirt_structs.h"

/*
** MESSAGES OUTPUT
*/
void		msg(char *id);
void		error_msg(char *id);
void		fatal_error_msg(char *error_msg);
/*
** SCENE CREATION
*/
t_res		*init_res(void);
t_amb_light	*init_amb_light(void);
t_cam		*init_cam(void);
t_light		*init_light(void);
t_pl		*init_pl(void);
t_sp		*init_sp(void);
t_sq		*init_sq(void);
t_cy		*init_cy(void);
t_tr		*init_tr(void);
void		link_cam(t_scene *scene, t_cam *new_cam);
void		link_light(t_scene *scene, t_light *new_light);
void		link_plane(t_scene *scene, t_pl *new_plane);
void		link_sphere(t_scene *scene, t_sp *new_sphere);
void		link_square(t_scene *scene, t_sq *new_square);
void		link_cylinder(t_scene *scene, t_cy *new_cylinder);
void		link_triangle(t_scene *scene, t_tr *new_triangle);
/*
** RT FILE PARSING
*/
int			reversed_strncmp(const char *s1, const char *s2, size_t n);
int			validate_line_chars(char *str);
int			is_int(char *str);
int			is_valid_char(char c);
int			is_number(char *str);
double		str_to_double(char *str);
int			count_snippets(char **line_snippets);
void		parse_file(char *file, t_scene *scene);
void		parse_line(int id_nb, t_scene *scene);
void		parse_res(t_scene *scene);
void		free_snippets(char **snippets, int nb);
void		parse_amb_light(t_scene *scene);
int			nonnegative_str_nb(char *str);
int			is_ratio(double n);
void		get_rgb(char **rgb, t_colors *color);
int			validate_rgb_bounds(t_colors color);
void		parse_cam(t_scene *scene);
t_tuples	str_to_tuple(char **xyz, int is_point);
void		parse_light(t_scene *scene);
void		parse_plane(t_scene *scene);
void		parse_sphere(t_scene *scene);
void		parse_square(t_scene *scene);
void		parse_cylinder(t_scene *scene);
void		parse_triangle(t_scene *scene);
/*
** MLX IMAGE RENDERING
*/
void		start_mlx(t_rt *rt);
void		render_img(t_rt *rt);
/*
** RAYTRACING
*/
t_ray		gen_ray(t_cam *cam, double x, double y);
void		bhaskara(double a, double b, double c, double *res);
t_tuples	get_hit_point(t_ray ray);
int			hit_all_spheres(t_ray *ray, t_sp *sphere);
int			hit_this_sphere(t_ray *ray, t_sp *sphere);

#endif
