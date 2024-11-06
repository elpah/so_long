/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:57:46 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/06 01:32:45 by elpah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_variables(t_game *game)
{
	game->map = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->direction = 'N';
	game->last_pos = '0';
	game->steps = 0;
	game->gate = 0;
	game->img_wh = 64;
	game->wiz_img = NULL;
	game->door[0] = NULL;
	game->door[1] = NULL;
	game->character[0] = NULL;
	game->character[1] = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->treasure = NULL;
	game->addr = NULL;
	game->collectibles = 0;
	game->collectibles_count = 0;
}

void	allocate_map(t_game *game, int line_count)
{
	if (!game)
		return ;
	game->map = ft_calloc((line_count + 1), sizeof(char *));
	if (game->map == NULL)
	{
		printf("Failed to allocate memory for map");
		return ;
	}
	game->map[line_count] = NULL;
}

void	fill_map(char **av, t_game *game, int line_count)
{
	int		fd;
	int		i;
	char	*str;

	fd = 0;
	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Unable to open map\n");
		return ;
	}
	str = get_next_line(fd);
	while (str != NULL && i < line_count)
	{
		game->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
}

void	set_row_col(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->total_rows = i;
	if (game->total_rows > 0)
		game->total_col = ft_strlen(game->map[1]);
	else
		game->total_col = 0;
}
