/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:58:25 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/19 12:58:27 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		player_numb(char *file)
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

void	write_file(t_inf *map)
{
	char	*tmp;
//	int		fd2;
	int		i_map;
	int		i_pie;

	i_map = 0;
	i_pie = 0;
//	fd2 = open("../text.txt", O_RDONLY);
	while (get_next_line(0, &tmp))
	{
		if (map->player == 0)
			map->player = player_numb(tmp);
		if (map->height == 0 && map->weight == 0)
			count_map_len(tmp, map);
		if (map->height > 0 && map->weight > 0 &&\
		map->row == 0 && map->column == 0)
			fill_start(map, tmp, &i_map);
		if (map->row == 0 && map->column == 0)
			count_piece_len(tmp, map);
		if (map->column > 0 && map->row > 0)
			copy_piece(tmp, map, &i_pie);
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp);
//	close(fd2);
}
