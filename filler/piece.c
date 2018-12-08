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

void	final_steps(t_inf *map, int *i)
{
	find_t(map);
	ft_printf("%d %d\n", map->t[0], map->t[1]);
	ft_arrfree_int(map->piece);
	map->column = 0;
	map->row = 0;
	*i = 0;
	map->t[0] = 0;
	map->t[1] = 0;
}

void	copy_piece(char *file, t_inf *map, int *i1)
{
	int i;
	int j1;

	i = -1;
	j1 = 0;
	while (file[++i])
	{
		if (file[i] == '*')
			map->piece[(*i1)][j1++] = -4;
		else if (file[i] == '.')
			map->piece[(*i1)][j1++] = -5;
		if (i + 1 == map->column && file[i + 1] == '\0')
		{
			map->piece[(*i1)][j1] = 0;
			break ;
		}
	}
	if (j1 != 0)
		(*i1)++;
	if ((*i1) == map->row)
	{
		map->piece[(*i1)] = 0;
		mk_distance(map);
		final_steps(map, i1);
	}
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
	while (file[i])
	{
		if (file[i] == 'e' && file[i + 1] == ' ')
		{
			i += 2;
			map->row = ft_atoi(&file[i]);
			i += 2;
			map->column = ft_atoi(&file[i]);
			break ;
		}
		i++;
	}
	if (map->column > 0 && map->row > 0)
		mk_piece(map);
}
