/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:32:35 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/07 16:13:39 by eobeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_exit(t_game *game, int row, int col)
{
	if (game->collectibles != game->collectibles_count)
	{
		ft_printf("You must collect all collectibles\n");
		change_position(game, row, col);
	}
	else
	{
		ft_printf("YOU WIN!!!\n");
		free_destroy(game);
	}
}

void	check_exit(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	if (game->collectibles == game->collectibles_count)
	{
		while (++row < game->total_rows)
		{
			col = -1;
			while (++col < game->total_col)
				if (game->map[row][col] == 'E')
					ft_put_img(game, game->door[1], row, col);
		}
	}
	else
		return ;
}

void	move_player(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1')
		return ;
	if (game->map[row][col] == '0' || game->map[row][col] == 'C')
	{
		if (game->map[row][col] == 'C')
		{
			game->map[row][col] = '0';
			game->collectibles_count++;
			check_exit(game);
		}
		change_position(game, row, col);
	}
	else if (game->map[row][col] == 'E')
		is_exit(game, row, col);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_destroy(game);
	else if (keycode == KEY_D || keycode == KEY_A)
		key_hook2(keycode, game);
	else if (keycode == KEY_W)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

void	key_hook2(int keycode, t_game *game)
{
	int	new_y;

	new_y = game->player_y;
	if (keycode == KEY_D && game->direction != 'R')
	{
		game->wiz_img = game->character[1];
		game->direction = 'R';
	}
	else if (keycode == KEY_A && game->direction != 'L')
	{
		game->wiz_img = game->character[0];
		game->direction = 'L';
	}
	ft_put_img(game, game->wiz_img, game->player_x, game->player_y);
	if (keycode == KEY_D)
		new_y += 1;
	else
		new_y -= 1;
	move_player(game, game->player_x, new_y);
}
