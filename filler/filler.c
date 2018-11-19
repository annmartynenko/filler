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
	size_t len;
	char *file1;
	int fd;
//	char *tmp;
//	char *file;
//	int fd2;

	file1 = write_file();
	len = ft_strlen(file1);
	fd = open("t.txt", O_WRONLY);
	dprintf(fd,"%zu", len);
	dprintf(fd,"%s", file1);
	close(fd);


//	fd2 = open("text.txt", O_RDONLY);
//	file = ft_strnew(0);
//	while (get_next_line(fd2, &tmp))
//	{
//		file = ft_strjoin(file, tmp);
//		//printf("%s\n", tmp);
//		ft_strdel(&tmp);
//	}
//	close(fd2);
//	printf("%s\n", file);
	return (0);
}