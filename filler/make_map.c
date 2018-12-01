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

void	fill_start(t_inf *map, char *cart, int *i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (cart[k])
	{
		if (cart[k] == '.')
			map->kart[(*i)][j++] = -3;
		else if (((cart[k] == 'O' || cart[k] == 'o') && map->player == 1) || \
		((cart[k] == 'X' || cart[k] == 'x') && map->player == 2))
			map->kart[(*i)][j++] = -1;
		else if (((cart[k] == 'X' || cart[k] == 'x') && map->player == 1) ||\
		((cart[k] == 'O' || cart[k] == 'o') && map->player == 2) )
			map->kart[(*i)][j++] = -2;
		if (cart[k + 1] && cart[k + 1] == '\0')
			map->kart[(*i)][j] = 0;
		k++;
	}
	if (j != 0)
		(*i)++;
	if ((*i) == map->height)
	{
		map->kart[(*i)] = 0;
		(*i) = 0;
	}
}

void	start_map(t_inf *map)
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

void	count_map_len(char *file, t_inf *map)
{
	int i;

	i = 0;
	while(file[i])
	{
		if(file[i] == 'u' && file[i + 1] == ' ')
		{
			i += 2;
			map->height = ft_atoi(&file[i]);
			i += 2;
			map->weight = ft_atoi(&file[i]);
			break ;
		}
		i++;
	}
	if (map->height > 0 && map->weight > 0)
		start_map(map);
}
/*
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

void	mke_map(t_inf *map)
{
	int		i;
	char	**cart;

	i = 0;
	cart = (char**)malloc(sizeof(char*) * map->height + 1);
	while (i < map->height)
	{
		cart[i] = (char*)malloc(sizeof(char) * map->weight + 1);
		i++;
	}
	//cart[i] = 0;
	//cart = copy_map(file, cart);

}
 */