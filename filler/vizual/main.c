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

int main()
{
	void *mlx;
	void *wind;
	int i;
	int j;
	t_viz map;

	map.player = 1;
	map.height = 0;
	map.kart = NULL;
	map.weight = 0;
	read_map(&map);
	//printf("%d %d\n", map.weight, map.weight);
	fflush(stdout);
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 800, 1000, "FILLER");
	i = 0;
	j = 0;
//	while (i < map.height)
//	{
//		j = 0;
//		while (j < 800)
//		{
//			mlx_pixel_put(mlx, wind, (j * 1000 / map.height), \
//        i, 0x62b4b3);
//	//printf("%d %d\n",(i * 1000 / map.height), (j * 1000 / map.weight));
////				mlx_pixel_put(mlx, wind, (i * 1000 / map.weight),\
////				(j * 1000 / map.height), 0xf2f181);
//			j++;
//		}
//		i++;
//	}
//	j = 0;
//	while (j < map.weight)
//	{
//		i = 0;
//		while (i < 1000)
//		{
//			mlx_pixel_put(mlx, wind, j, \
//        (i * 800 / map.weight), 0x62b4b3);
//			//printf("%d %d\n",(i * 1000 / map.height), (j * 1000 / map.weight));
////				mlx_pixel_put(mlx, wind, (i * 1000 / map.weight),\
////				(j * 1000 / map.height), 0xf2f181);
//			i++;
//		}
//		j++;
//	}
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.weight)
		{
			if (map.kart[i][j] == -1)
			{
				draw((j * 1000 / map.height), \
                (i * 800 / map.weight), map, mlx, wind);
			}
			else if (map.kart[i][j] == -2)
				draw_q((j * 1000 / map.height),\
				(i * 800 / map.weight) , map, mlx, wind);
			j++;
		}
		i++;
	}
//	i = 150;
//	while (j < 175)
//	{
//		i = 150;
//		while (i < 175)
//		{
//			mlx_pixel_put(mlx, wind, i, j, 0x62b4b3);
//			i++;
//		}
//		j++;
//	}
//	j = 75;
//	while (j < 100)
//	{
//	   i = 75;
//	   while (i < 100)
//	   {
//		   mlx_pixel_put(mlx, wind, i, j, 0xf2f181);
//		   i++;
//	   }
//	   j++;
//	}
	mlx_loop(mlx);
	return (0);
}
