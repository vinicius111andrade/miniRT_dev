/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:08:04 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/20 19:47:51 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define	WIN1_SX		242
#define	WIN1_SY		242

int		minirt()
{
	printf("\nMake compilou tudo!");
	return 0;
}

int		main()
{
	void	*mlx;
	void	*win1;

	minirt();
	printf("MinilibX Test Program\n");
	mlx = mlx_init();
	win1 = mlx_new_window(mlx, WIN1_SX, WIN1_SY, "Minha janelinha top");
	mlx_pixel_put(mlx, win1, 10, 10, 0066660000);
	mlx_loop(mlx);
	return 0;
}