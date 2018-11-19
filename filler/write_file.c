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
#include "stdio.h"
int 	player_numb(char *file)
{
	int i;
	int play_n;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == ' ' && file[i + 1] == 'p')
			play_n = ft_atoi(&file[i + 2]);
	}
	return (play_n);
}

char	*write_file()
{
	char *tmp;
	char *file;
	//int fd2;

	//fd2 = open("text.txt", O_RDONLY);
	file = ft_strnew(0);
	while (get_next_line(0, &tmp))
	{
		file = ft_strjoin(file, tmp);
		printf("fd %s", tmp);
		ft_strdel(&tmp);
	}
	//close(fd2);
	return (file);
}