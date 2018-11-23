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

void	mk_distance(t_inf *map)
{
	int i;
	int j;
	int n;

	i = 0;
	n = 1;
	while(i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			if (map->kart[i][j] == -2 || map->kart[i][j] == n - 1)
			{
				map->kart[i][j + 1] = n;
				map->kart[i][j - 1] = n;
				map->kart[i + 1][j] = n;
				map->kart[i - 1][j] = n;
				n++;
			}
		}
		i++;
	}
}