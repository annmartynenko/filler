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
//	int		fd;
//	int		i;
//	int		j;

	map.column = 0;
	map.height = 0;
	map.player = 0;
	map.row = 0;
	map.weight = 0;
	map.kart = NULL;
	map.piece = NULL;
	map.t[0] = 0;
	map.t[1] = 0;
	write_file(&map);
//	fd = open("t.txt", O_WRONLY);
	system("leaks amartyne.filler >> t.txt");
//	close(fd);
	return (0);
}