/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:34:55 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/04 14:34:56 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vizual.h"
#include <stdio.h>

void	draw(int x, int y, t_viz map, void *mlx, void *wind)
{
	int i;
	int j;

	j = y;
	i = x;
	printf("x %d y %d\n", x, y);
	printf("x/w %d y/h %d\n", 800 / map.weight, 1000 / map.height);
	while(y < (j + 1000 / map.height) )
	{
		x = i;
		while (x < (i + 800 / map.weight) )
		{
			mlx_pixel_put(mlx, wind, x, y, 0xf2f181);
			x++;
		}
		y++;
	}
}

void	draw_q(int x, int y, t_viz map, void *mlx, void *wind)
{
	int i;
	int j;

	j = y;
	i = x;
	printf("x %d y %d\n", x, y);
	printf("x/w %d y/h %d\n", 800 / map.weight, 1000 / map.height);
	while(y < (j + 1000 / map.height) )
	{
		x = i;
		while (x < (i + 800 / map.weight) )
		{
			mlx_pixel_put(mlx, wind, x, y, 0x90ee90);
			x++;
		}
		y++;
	}
}
