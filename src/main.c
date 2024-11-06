/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:40:58 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/03 00:20:54 by elpah            ###   ########.fr       */
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

	init_game_variables(&game);
	count = 0;
	if (ac != 2)
		return (ft_printf("Error\n:invalid number of Arguments\n"), 1);
	if (!is_valid_file(av[1]))
		return (ft_printf("Error\n:Invalid File\n"), 2);
	count = count_lines(av);
	allocate_map(&game, count);
	fill_map(av, &game, count);
	if (map_is_valid(&game))
	{
		find_player_position(&game);
		game.collectibles = count_chars(game.map, 'C');
		set_row_col(&game);
		if (check_collectibles(&game) == 1)
			launch_graphics(&game);
		else
			ft_printf("Error\n:Map is not valid");
	}
	free_map(&game);
	return (0);
}
