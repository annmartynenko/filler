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

void	draw(int x, int y, t_viz *map, int color)
{
	int i;
	int j;

	j = y;
	i = x;
	while (x < (i + 800 / map->height))
	{
		y = j;
		while (y < (j + 700 / map->weight))
		{
			mlx_pixel_put(map->mlx, map->wind, y, x, color);
			y++;
		}
		x++;
	}
}

void	mke_window(t_viz *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->weight)
		{
			if (map->kart[i][j] == -1)
			{
				draw((i * 900 / map->height),\
				(j * 900 / map->weight), map, 0xf2f181);
			}
			else if (map->kart[i][j] == -2)
				draw((i * 900 / map->height),\
				(j * 900 / map->weight), map, 0x90ee90);
			else if (map->kart[i][j] == -4)
				draw((i * 900 / map->height),\
				(j * 900 / map->weight), map, 0x68cfa4);
			else if (map->kart[i][j] == -5)
				draw((i * 900 / map->height),\
				(j * 900 / map->weight), map, 0xfcfcb8);
		}
	}
}
