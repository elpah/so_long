/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:40:58 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/03 00:17:05 by elpah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int count_lines(char **av)
{
	int fd;
	int count;
	char *str;

	count = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n:Unable to open file");
		exit(1);
	}
	str = get_next_line(fd);
	if (!str)
		count = 1;
	while ((str) != NULL)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int main(int ac, char **av)
{
	t_game game;
	int count;
	return (0);
}
