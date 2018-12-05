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

void	final(t_viz *map)
{
	int fd2;
	int i;
	int j;

	fd2 = open("final.txt", O_WRONLY);
	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			dprintf(fd2, "%d ", map->kart[i][j]);
			j++;
		}
		dprintf(fd2, "\n");
		i++;
	}
	close(fd2);
}

int read_map(t_viz *map, void *mlx, void *wind)
{
	char *tmp;
	int fd;
	int i_map;

	i_map = 0;
	fd = open("karta.txt", O_RDONLY);
	while (get_next_line(0, &tmp))
	{
		//printf("%s \n", tmp);
//		if (map->player == 0)
//			map->player = player_numb_v(tmp);
		//printf("%d %d %d\n", map->weight, map->height, i_map);
		if (map->height == 0 && map->weight == 0)
		{
			count_map_len_v(tmp, map);
			//printf("111\n");
		}
		//printf("444\n");
		if (map->height > 0 && map->weight > 0 && tmp[0] == '0')
		{
			//printf("555\n");
			fill_start_v(map, tmp, &i_map);
			//printf("222\n");
		}
		if (i_map == map->height && i_map > 0)
		{
			mke_window(map, mlx, wind);
			i_map = 0;
			final(map);
		}
		ft_strdel(&tmp);
	}
	close(fd);
	return(1);
}