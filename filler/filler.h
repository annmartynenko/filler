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
# include "get_next_line.h"

typedef struct 	s_inf
{
	int weight;
	int height;
	int player;
	int **kart;
	char **piece;
}				t_inf;

char	**write_file(t_inf *map);
int 	player_numb(char **file);
char	**mke_map(char **file, t_inf *map);
char	**mk_piece(char **file);
void	mk_distance(t_inf *map);

#endif