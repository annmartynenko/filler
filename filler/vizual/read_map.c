/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:58:19 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/03 16:58:21 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizual.h"
#include <stdio.h>


int		player_numb_v(char *file)
{
	int i;
	int play_n;

	i = 0;
	play_n = 0;
	while (file[i] != '\0')
	{
		if (file[i] == ' ' && file[i + 1] == 'p')
		{
			play_n = ft_atoi(&file[i + 2]);
			break ;
		}
		i++;
	}
	return (play_n);
}

int read_map(t_viz *map)
{
	char *tmp;
	int fd;
	int fd2;
	int i_map;
	int i;
	int j;

	i_map = 0;
	fd = open("karta.txt", O_RDONLY);
	fd2 = open("final.txt", O_WRONLY);
	while (get_next_line(fd, &tmp))
	{
		printf("%s \n", tmp);
//		if (map->player == 0)
//			map->player = player_numb_v(tmp);
		if (map->height == 0 && map->weight == 0)
			count_map_len_v(tmp, map);
		if (map->height > 0 && map->weight > 0)
			fill_start_v(map, tmp, &i_map);
		if (i_map == map->height)
			break ;
	}
	i = 0;
	printf("%d %d %d\n", map->weight, map->height, map->player);
	while(i < map->height)
	{
		j = 0;
		while (j < map->height)
		{
			dprintf(fd2, "%d ", map->kart[i][j]);
			j++;
		}
		dprintf(fd2, "\n");
		i++;
	}
	close(fd);
	return(1);
}