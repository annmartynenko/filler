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
	char **file1;
	int fd;
	int i;

	i = 0;
	file1 = write_file();
	fd = open("../t.txt", O_WRONLY);
	while (file1[i] != 0)
	{
		dprintf(fd, "%s\n", file1[i]);
		i++;
	}
	close(fd);
	return (0);
}