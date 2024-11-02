/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:06:50 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/02 04:35:21 by elpah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void find_player_position(t_game *game_map)
{
	int i;
	int j;

	if (!game_map || !game_map->map)
		return;
	i = 0;
	while (game_map->map[i])
	{
		j = 0;
		while (game_map->map[i][j])
		{
			if (game_map->map[i][j] == 'P')
			{
				game_map->player_x = j;
				game_map->player_y = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void flood_fill(t_game *game, int x, int y, bool **visited)
{
	if (x < 0 || x >= game->total_rows || y < 0 || y >= game->total_col)
		return;
	if (visited[x][y] || game->map[x][y] == '1')
		return;
	visited[x][y] = true;
	flood_fill(game, x - 1, y, visited);
	flood_fill(game, x + 1, y, visited);
	flood_fill(game, x, y - 1, visited);
	flood_fill(game, x, y + 1, visited);
}

bool **create_visited_array(int rows, int cols)
{
	int i;
	int j;
	bool **visited;

	visited = (bool **)malloc(rows * sizeof(bool *));
	i = 0;
	while (i < rows)
	{
		visited[i] = (bool *)malloc(cols * sizeof(bool));
		j = 0;
		while (j < cols)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
	return (visited);
}

bool all_collectibles_reachable(t_game *game, bool **visited)
{
	int i;
	int j;

	i = 0;
	while (i < game->total_rows)
	{
		j = 0;
		while (j < game->total_col)
		{
			if (game->map[i][j] == 'C' && !visited[i][j])
				return (false);
			if (game->map[i][j] == 'E' && !visited[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int check_collectibles(t_game *game)
{
	bool **visited;
	int i;

	visited = create_visited_array(game->total_rows, game->total_col);
	i = 0;
	flood_fill(game, game->player_y, game->player_x, visited);
	if (all_collectibles_reachable(game, visited))
	{
		while (i < game->total_rows)
			free(visited[i++]);
		free(visited);
		return (1);
	}
	else
	{
		while (i < game->total_rows)
			free(visited[i++]);
		free(visited);
		return (0);
	}
}
