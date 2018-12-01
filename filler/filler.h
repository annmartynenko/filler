/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:54:10 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/13 18:57:02 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct 	s_inf
{
	int weight;
	int height;
	int player;
	int row;
	int column;
	int **kart;
	int **piece;
	int t[2];
}				t_inf;

void	write_file(t_inf *map);
int 	player_numb(char *file);
void	mke_map(t_inf *map);
void	mk_piece(t_inf *map);
void	mk_distance(t_inf *map);
void	find_t(t_inf *map);
int		can_insert(t_inf *map, int i, int j);
void	count_map_len(char *file, t_inf *map);
void	count_piece_len(char *file, t_inf *map);
void	start_map(t_inf *map);
void	fill_start(t_inf *map, char *cart, int *i);
void	copy_piece(char *file, t_inf *map, int *i1);

#endif