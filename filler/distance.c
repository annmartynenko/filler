/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:04:36 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/23 20:04:37 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

void	ok_position(t_inf *map, int i, int j, int n)
{
	if (i + 1 < map->height)
		if (map->kart[i + 1][j] && map->kart[i + 1][j] == -3)
			map->kart[i + 1][j] = n;
	if (i - 1 >= 0)
		if (map->kart[i - 1][j] && map->kart[i - 1][j] == -3)
			map->kart[i - 1][j] = n;
	if (j + 1 < map->weight)
		if (map->kart[i][j + 1] && map->kart[i][j + 1] == -3)
			map->kart[i][j + 1] = n;
	if (j - 1 >= 0)
		if (map->kart[i][j - 1] && map->kart[i][j - 1] == -3)
			map->kart[i][j - 1] = n;
}

void	mk_distance(t_inf *map)
{
	int i;
	int j;
	int n;
	int a;

	n = 1;
	a = 0;
	while (a < map->weight * map->height - 2)
	{
		i = 0;
		while (i < map->height)
		{
			j = 0;
			while (j < map->weight)
			{
				if (map->kart[i][j] == -2 || map->kart[i][j] == n - 1)
					ok_position(map, i, j, n);
				j++;
			}
			i++;
		}
		n++;
		a++;
	}
}