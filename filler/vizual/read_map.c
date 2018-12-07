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

void	result(char *tmp, t_viz *map)
{
	if (ft_strncmp("== O fin:", tmp, 9))
		mlx_string_put(map->mlx, map->wind, 300, 950, 0xf2f181, ft_itoa(ft_atoi(&tmp[9])));
	else if (ft_strncmp("== X fin:", tmp, 9))
		mlx_string_put(map->mlx, map->wind, 800, 950, 0x90ee90, ft_itoa(ft_atoi(&tmp[9])));
}

int		read_map(t_viz *map)
{
	char	*tmp;
	int		i_map;

	i_map = 0;
	while (get_next_line(0, &tmp))
	{
		if (ft_strnstr("== ", tmp, 3) > 0)
		{
			printf("%s\n", tmp);
			result(tmp, map);
		}
		if (map->player == 0)
			player_numb_v(tmp);
		if (map->height == 0 && map->weight == 0)
			count_map_len_v(tmp, map);
		if (map->height > 0 && map->weight > 0 && tmp[0] == '0')
			fill_start_v(map, tmp, &i_map);
		if (i_map == map->height && i_map > 0)
			break ;
		ft_strdel(&tmp);
	}
	if (get_next_line(0, &tmp))
	{
		printf("%s\n", tmp);
		if (ft_strnstr("== ", tmp, 3) > 0)
			result(tmp, map);
	}
	mlx_clear_window(map->mlx, map->wind);
	mlx_string_put(map->mlx, map->wind, 200, 950, 0xf2f181, "player 1");
	mlx_string_put(map->mlx, map->wind, 600, 950, 0x90ee90, "player 2");
	mke_window(map);
	return (1);
}
