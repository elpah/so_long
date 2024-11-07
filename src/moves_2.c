/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:37:01 by eobeng            #+#    #+#             */
/*   Updated: 2024/10/26 18:49:07 by eobeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position(t_game *game, int row, int col)
{
	if (game->last_pos == '0')
		ft_put_img(game, game->floor, game->player_x, game->player_y);
	else if (game->last_pos == 'E')
		ft_put_img(game, game->door[0], game->player_x, game->player_y);
	game->map[game->player_x][game->player_y] = game->last_pos;
	ft_put_img(game, game->wiz_img, row, col);
	game->last_pos = game->map[row][col];
	game->player_x = row;
	game->player_y = col;
	game->steps++;
	ft_printf("steps: %i\tcollectibles: %i/%i\n",
		game->steps, game->collectibles_count, game->collectibles);
}
