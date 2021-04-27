/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:08:04 by vde-melo          #+#    #+#             */
/*   Updated: 2021/04/27 20:12:22 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char *argv[])
{
	t_rt	rt;

	if (argc < 2)
		fatal_error_msg("010");
	else if (argc > 3)
		fatal_error_msg("012");
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
		fatal_error_msg("013");
	ft_bzero(&rt, sizeof(t_rt));
	rt.save = (argc == 3);
	parse_file(argv[1], &rt.scene);
	//test_parsing(&rt.scene); //retirar o teste
	start_mlx(&rt);
	render_img(&rt);
	//if (rt.save == 0)
	//	run_mlx_window(&rt);
	//else
	//	save_bitmaps(&rt);
	//exit(EXIT_FAILURE); //solucao temp pra desalocar tudo
	//tem q fechar o mlx_loop em algum momento
	mlx_loop(rt.mlx.mlx);
	return (0);
}
