/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:08:04 by vde-melo          #+#    #+#             */
/*   Updated: 2021/02/08 20:02:48 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define	WIN1_SX		242
#define	WIN1_SY		242

int		main(int argc, char *argv[])
{
	// void	*mlx;
	// void	*win1;

	if (argc < 2)
		fatal_error_msg("010");
	else if (argc > 3)
		fatal_error_msg("012");
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
		fatal_error_msg("013");
	if (argc == 3)
		msg("014");
	msg("011");
	// mlx = mlx_init();
	// win1 = mlx_new_window(mlx, WIN1_SX, WIN1_SY, "Minha janelinha top");
	// mlx_pixel_put(mlx, win1, 10, 10, 0066660000);
	// mlx_loop(mlx);
	return 0;
}
