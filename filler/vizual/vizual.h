/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:32:24 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/03 17:32:25 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZUAL_H
# define VIZUAL_H

# include "../filler.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct	s_viz
{
	int player;
	int weight;
	int height;
	int **kart;
}				t_viz;

void	fill_start_v(t_viz *map, char *cart, int *i);
void	count_map_len_v(char *file, t_viz *map);
int 	read_map(t_viz *map, void *mlx, void *wind);
void	draw(int x, int y, t_viz map, void *mlx, void *wind);
void	draw_q(int x, int y, t_viz map, void *mlx, void *wind);
void	mke_window(t_viz *map, void *mlx, void *wind);

#endif