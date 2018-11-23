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

#include "filler.h"
#include "stdio.h"

void	fill_start(t_inf *map, char **cart)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			if (cart[i][j] == '.')
				map->kart[i][j] = -3;
			else if ((cart[i][j] == 'O' && map->player == 1) ||\
			(cart[i][j] == 'X' && map->player == 2))
				map->kart[i][j] = -1;
			else if ((cart[i][j] == 'X' && map->player == 1) ||\
			(cart[i][j] == 'O' && map->player == 2))
				map->kart[i][j] = -2;
			j++;
		}
		i++;
	}
}

void	start_map(t_inf *map, char **cart)
{
	int i;

	i = 0;
	map->kart = (int**)malloc(sizeof(int*) * map->height + 1);
	while (i < map->height)
	{
		map->kart[i] = (int*)malloc(sizeof(int) * map->weight + 1);
		i++;
	}
	fill_start(map, cart);
}

int		count_map_len(char **file, int *column)
{
	int row;
	int i;
	int j;

	i = 0;
	row = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'u' && file[i][j + 1] == ' ')
			{
				j += 2;
				row = ft_atoi((file[i] + j));
				j += 2;
				*column = ft_atoi((file[i] + j));
				break ;
			}
			j++;
		}
		if (row != 0)
			break ;
		i++;
	}
	return (row);
}

char	**copy_map(char **file, char **map)
{
	int i;
	int j;
	int i1;
	int j1;

	i = 0;
	i1 = 0;
	while(file[i])
	{
		j = 0;
		j1 = 0;
		while(file[i][j])
		{
			if ((file[i][j] == '.' || file[i][j] == 'O' ||\
			file[i][j] == 'X') && (file[i][j + 1] == '.' || file[i][j + 1] == 'O' ||\
			file[i][j + 1] == 'X' || file[i][j + 1] == '\0'))
			{
				map[i1][j1] = file[i][j];
				j1++;
			}
			if ((file[i][j] == '.' || file[i][j] == 'O' ||\
			file[i][j] == 'X') && file[i][j + 1] == '\0')
			{
				map[i1][j1] = '\0';
				i1++;
			}
			j++;
		}
		i++;
	}
	map[i1] = 0;
	return (map);
}

char	**mke_map(char **file, t_inf *map)
{
	int		i;
	char	**cart;

	i = 0;
	map->height = count_map_len(file, &map->weight);
	cart = (char**)malloc(sizeof(char*) * map->height + 1);
	while (i < map->height)
	{
		cart[i] = (char*)malloc(sizeof(char) * map->weight + 1);
		i++;
	}
	//map[i] = 0;
	cart = copy_map(file, cart);
	start_map(map, cart);
	mk_distance(map);
	return (cart);
}