/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:58:28 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/03 16:58:36 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vizual.h"
#include <stdio.h>

int	exit_x(t_viz *map)
{
	(void)map;
	exit(1);
	return (0);
}

int	main(void)
{
	t_viz map;

	map.player = 0;
	map.height = 0;
	map.kart = NULL;
	map.weight = 0;
	map.resO = NULL;
	map.resX = NULL;
	fflush(stdout);
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, 900, 1000, "FILLER");
	mlx_loop_hook(map.mlx, read_map, &map);
	mlx_hook(map.wind, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
	return (0);
}
