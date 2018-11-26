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
#include "stdio.h"

int		count_distance(t_inf *map, int i, int j)
{
	int x;
	int y;
	int diff_x;
	int diff_y;
	int distance;

	x = 0;
	diff_x = 0;
	diff_y = 0;
	distance = 0;
	while (map->piece[x])
	{
		y = 0;
		while (map->piece[x][y])
		{
			if (map->piece[x][y] == -4 )
			{
				if (diff_x == 0 && diff_y == 0)
				{
					distance += map->kart[i + diff_x][j + diff_y];
					diff_x = x;
					diff_y = y;
				}
				else
				{
					diff_x = x - diff_x;
					diff_y = y - diff_y;
					distance += map->kart[i + diff_x][j + diff_y];
				}
				j++;
			}
			y++;
		}
		x++;
	}
	return (distance);
}

void	result_t(t_inf *map)
{
	int x;
	int y;

	x = 0;
	if (map->piece[0][0] == -5)
	{
		while (map->piece[x])
		{
			y = 0;
			while (map->piece[x][y])
			{
				if (map->piece[x][y] == -4)
				{
					map->t[0] -= x;
					map->t[1] -= y;
					break ;
				}
				y++;
			}
			if (map->piece[x][y] == -4)
				break ;
			x++;
		}
	}
}

void	find_t(t_inf *map)
{
	int i;
	int j;
	int min_distance;
	int distance_now;

	i = 0;
	map->t = (int*)malloc(sizeof(int) * 2);
	min_distance = map->weight * map->height;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
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
			j++;
		}
		i++;
	}
	result_t(map);
}