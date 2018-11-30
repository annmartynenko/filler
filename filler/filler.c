/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:18:22 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/13 16:18:25 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
int main()
{
	t_inf	map;
	int		fd;
	int		i;
	int		j;

	map.column = 0;
	map.height = 0;
	map.player = 0;
	map.row = 0;
	map.weight = 0;
	map.kart = NULL;
	map.piece = NULL;
	map.t = NULL;
	write_file(&map);
	printf("%d %d\n", map.t[0], map.t[1]);
	fd = open("../t.txt", O_WRONLY);
	i = 0;
	j = 0;
	while (map.kart[i] != 0)
	{
		while (map.kart[i][j])
		{
			dprintf(fd, " %d ", map.kart[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		i++;
	}

	i = 0;

	while (i < map.height)
	{
		j = 0;
		while (j < map.weight)
		{
			dprintf(fd, " %d ", map.kart[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		i++;
	}
		i = 0;
	j = 0;
	while (map.piece[i] != 0)
	{
		j = 0;
		while (map.piece[i][j])
		{
			dprintf(fd, " %d ", map.piece[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		i++;
	}
	dprintf(fd, "result %d %d\n", map.t[0], map.t[1]);
	close(fd);
	return (0);
}