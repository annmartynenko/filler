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

int		count_piece_len(char **file, int *column)
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
			if(file[i][j] == 'e' && file[i][j + 1] == ' ')
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

char	**copy_piece(char **file, char **piec)
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
			if ((file[i][j] == '*' || file[i][j] == '.') &&\
			(file[i][j + 1] == '*' || file[i][j + 1] == '.' ||\
			file[i][j + 1] == '\0'))
			{
				piec[i1][j1] = file[i][j];
				j1++;
			}
			if (file[i][j] == '*' && file[i][j + 1] == '\0')
			{
				piec[i1][j1] = '\0';
				i1++;
			}
			j++;
		}
		i++;
	}
	piec[i1] = 0;
	return (piec);
}

char **mk_piece(char **file)
{
	int		i;
	char	**piec;
	int		column;
	int 	row;

	i = 0;
	row = count_piece_len(file, &column);
	piec = (char**)malloc(sizeof(char*) * row + 1);
	while (i < row)
	{
		piec[i] = (char*)malloc(sizeof(char) * column + 1);
		i++;
	}
	piec = copy_piece(file, piec);
	return (piec);
}