/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:55:01 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/24 16:55:02 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

int in_frames(t_inf *map, int i, int j)
{
	if (i < map->height && j < map->weight)
		return (1);
	return (0);
}

int		can_insert(t_inf *map, int i, int j)
{
	int x;
	int y;
	int numb_t;

	x = 0;
	numb_t = 0;
	while (map->piece[x])
	{
		y = 0;
		while (map->piece[x][y])
		{
			if (map->piece[x][y] == -4)
			{
				//printf("i j %d %d, x y %d %d \n",i ,j, x, y);
				if ((i + x) < map->height && (j + y) < map->weight)
				{
					if (map->kart[i + x][j + y] == -1)
						numb_t++;
					if (numb_t > 1 || !in_frames(map, i, j) || \
                (map->kart[i + x][j + y] == -2))
						return (0);
				}
				else
					return (0);
			}
			y++;
		}
		x++;
	}
	if (numb_t == 0 || numb_t > 1)
		return (0);
	return (1);
}