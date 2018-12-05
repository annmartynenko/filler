/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:34:55 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/04 14:34:56 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vizual.h"
#include <stdio.h>

void	draw(int x, int y, t_viz map, void *mlx, void *wind)
{
	int i;
	int j;

	j = y;
	i = x;
	//printf("x %d y %d\n", x, y);
	//printf("x/w %d y/h %d\n", 800 / map.weight, 1000 / map.height);
	while(x < (i + 1000 / map.height) )
	{
		y = j;
		while (y < (j + 1000 / map.weight) )
		{
			mlx_pixel_put(mlx, wind, y, x, 0xf2f181);
			y++;
		}
		x++;
	}
}

void	draw_q(int x, int y, t_viz map, void *mlx, void *wind)
{
	int i;
	int j;

	j = y;
	i = x;
	//printf("x %d y %d\n", x, y);
	//printf("x/w %d y/h %d\n", 800 / map.weight, 1000 / map.height);
	while(x < (i + 1000 / map.height) )
	{
		y = j;
		while (y < (j + 1000 / map.weight) )
		{
			mlx_pixel_put(mlx, wind, y, x, 0x90ee90);
			y++;
		}
		x++;
	}
}

void	mke_window(t_viz *map, void *mlx, void *wind)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			if (map->kart[i][j] == -1)
			{
				draw((i * 1000 / map->height), \
                (j * 1000 / map->weight), *map, mlx, wind);
			}
			else if (map->kart[i][j] == -2)
				draw_q((i * 1000 / map->height),\
				(j * 1000 / map->weight) , *map, mlx, wind);
			j++;
		}
		i++;
	}
}