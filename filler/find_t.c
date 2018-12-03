/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:25:21 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/26 13:25:22 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_distance(t_inf *map, int i, int j)
{
	int x;
	int y;
	int distance;

	x = -1;
	distance = 0;
	while (map->piece[++x])
	{
		y = -1;
		while (map->piece[x][++y])
		{
			if (map->piece[x][y] == -4)
			{
				if (map->kart[i + x][j + y] != -1)
				{
					if (map->kart[i + x][j + y] == -3)
						distance += map->weight;
					else
						distance += map->kart[i + x][j + y];
				}
			}
		}
	}
	return (distance);
}

void	find_t(t_inf *map)
{
	int i;
	int j;
	int min_distance;
	int distance_now;

	i = -1;
	min_distance = map->weight * map->height;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->weight)
		{
			if (can_insert(map, i, j))
			{
				distance_now = count_distance(map, i, j);
				if (min_distance > distance_now)
				{
					map->t[0] = i;
					map->t[1] = j;
					min_distance = distance_now;
				}
			}
		}
	}
}
