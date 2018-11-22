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

char	**mke_map(char **file)
{
	int column;
	int i;
	char **map;

	i = 0;
	column = 0;
	map = (char**)malloc(sizeof(char*) * count_map_len(file, &column) + 1);
	while (map[i])
	{
		map[i] = (char*)malloc(sizeof(char) * column + 1);
		i++;
	}
	//map[i] = 0;
	map = copy_map(file, map);
	return (map);
}