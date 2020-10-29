/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:08:04 by vde-melo          #+#    #+#             */
/*   Updated: 2020/10/08 13:33:20 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		minirt()
{
	test_makefile_tests();
	test_makefile_mymath();
	printf("\nMake compilou tudo!");
	return 0;
}

int		main()
{
	minirt();
	return 0;
}