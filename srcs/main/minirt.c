/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:08:04 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/10 17:37:38 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define	WIN1_SX		242
#define	WIN1_SY		242

int		main(int argc, char *argv[])
{
	// void	*mlx;
	// void	*win1;
	t_rt	rt;

	if (argc < 2)
		fatal_error_msg("010");
	else if (argc > 3)
		fatal_error_msg("012");
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
		fatal_error_msg("013");
	rt.save = (argc == 3); //ver se esta funcioando, save eh type int
	parse_file(argv[1], &rt.scene);
	// mlx = mlx_init();
	// win1 = mlx_new_window(mlx, WIN1_SX, WIN1_SY, "Minha janelinha top");
	// mlx_pixel_put(mlx, win1, 10, 10, 0066660000);
	// mlx_loop(mlx);
	return 0;
}
