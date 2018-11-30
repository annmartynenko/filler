/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:23:03 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/23 15:23:05 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

void	copy_piece(char *file, t_inf *map, int *i1)
{
	int i;
	int j1;

	i = 0;
	j1 = 0;
	if ((*i1) == map->row)
		map->piece[(*i1)] = 0;
	while(file[i])
	{
		if (file[i] == '*')
			map->piece[(*i1)][j1++] = -4;
		else if (file[i] == '.')
			map->piece[(*i1)][j1++] = -5;
		if (file[i + 1] && file[i + 1] == '\0')
		{
			map->piece[(*i1)] = 0;
			break;
		}
		i++;
	}
	if (j1 != 0)
		(*i1)++;
	if ((*i1) == map->row)
		map->piece[(*i1)] = 0;
}

void	mk_piece(t_inf *map)
{
	int		i;

	i = 0;
	map->piece = (int**)malloc(sizeof(int*) * map->row + 1);
	while (i < map->row)
	{
		map->piece[i] = (int*)malloc(sizeof(int) * map->column + 1);
		i++;
	}
}

void	count_piece_len(char *file, t_inf *map)
{
	int i;

	i = 0;
	while(file[i])
	{
		if(file[i] == 'e' && file[i + 1] == ' ')
		{
			i += 2;
			map->row = ft_atoi(&file[i]);
			i += 2;
			map->column = ft_atoi(&file[i]);
			break ;
		}
		i++;
	}
	mk_piece(map);
}

