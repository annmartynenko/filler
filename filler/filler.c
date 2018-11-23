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
	char	**mp;

	i = 0;
	mp = write_file(&map);
	fd = open("../t.txt", O_WRONLY);
//	while (mp[i] != 0)
//	{
//		dprintf(fd, "%s\n", mp[i]);
//		i++;
//	}
	dprintf(fd, "%d\n", map.player);
	i = 0;
	while (map.piece[i] != 0)
	{
		dprintf(fd, "%s\n", map.piece[i]);
		i++;
	}
	i = 0;
	while (map.kart[i] != 0)
	{
		j = 0;
		while (map.kart[i][j])
		{
			dprintf(fd, " %d ", map.kart[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		i++;
	}
	close(fd);
	return (0);
}