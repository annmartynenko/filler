/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:31:24 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/22 17:31:26 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizual.h"
#include <stdio.h>

void	fill_start_v(t_viz *map, char *cart, int *i)
{
	int j;
	int k;

	j = 0;
	k = -1;
	while (cart[++k])
	{
		if (cart[k] == '.')
			map->kart[(*i)][j++] = -3;
		else if (cart[k] == 'O' || cart[k] == 'o')
			map->kart[(*i)][j++] = -1;
		else if (cart[k] == 'X' || cart[k] == 'x')
			map->kart[(*i)][j++] = -2;
		if (k + 1 == map->weight + 4 && cart[k + 1] == '\0')
			map->kart[(*i)][j] = 0;
	}
	if (j != 0)
		(*i)++;
	if ((*i) == map->height)
		map->kart[(*i)] = 0;
}

void	start_map_v(t_viz *map)
{
	int i;

	i = 0;
	map->kart = (int**)malloc(sizeof(int*) * map->height + 1);
	while (i < map->height)
	{
		map->kart[i] = (int*)malloc(sizeof(int) * map->weight + 1);
		i++;
	}
}

void	count_map_len_v(char *file, t_viz *map)
{
	int i;

	i = 0;
	while (file[i])
	{
		printf("%c\n", file[i]);
		if (file[i] == 'u' && file[i + 1] == ' ')
		{
			i += 2;
			map->height = ft_atoi(&file[i]);
			printf("%c\n", file[i]);
			if (map->height < 100)
				i += 2;
			else
				i += 3;
			map->weight = ft_atoi(&file[i]);
			break ;
		}
		i++;
	}
	printf("%d %d %d\n", map->weight, map->weight , i);
	if (map->height > 0 && map->weight > 0)
	{
		start_map_v(map);
		printf("333\n");
	}
}
