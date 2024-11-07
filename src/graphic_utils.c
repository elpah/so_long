/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:32:48 by eobeng            #+#    #+#             */
/*   Updated: 2024/10/26 19:13:26 by eobeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->character[0]);
	mlx_destroy_image(game->mlx, game->character[1]);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->treasure);
	mlx_destroy_image(game->mlx, game->door[0]);
	mlx_destroy_image(game->mlx, game->door[1]);
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
}

void	ft_put_img(t_game *game, void *img, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		img, SIZE * col, SIZE * row);
}

void	init_map(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->total_rows)
	{
		col = -1;
		while (++col < game->total_col)
		{
			if (game->map[row][col] == '1')
				ft_put_img(game, game->wall, row, col);
			else if (game->map[row][col] == '0')
				ft_put_img(game, game->floor, row, col);
			else if (game->map[row][col] == 'C')
				ft_put_img(game, game->treasure, row, col);
			else if (game->map[row][col] == 'P')
			{
				game->player_x = row;
				game->player_y = col;
				ft_put_img(game, game->wiz_img, row, col);
			}
			else if (game->map[row][col] == 'E')
				ft_put_img(game, game->door[0], row, col);
		}
	}
}

void	load_wall_door(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_WALL, &game->img_wh, &game->img_wh);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_FLOOR, &game->img_wh, &game->img_wh);
	game->door[0] = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_DOOR_CLOSE, &game->img_wh, &game->img_wh);
	game->door[1] = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_DOOR_OPEN, &game->img_wh, &game->img_wh);
}

void	load_player_and_collectibles(t_game *game)
{
	game->treasure = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_COLLECTIBLE, &game->img_wh, &game->img_wh);
	game->character[0] = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_CHARACTER_LEFT, &game->img_wh, &game->img_wh);
	game->character[1] = mlx_xpm_file_to_image(game->mlx,
			TEXTURE_CHARACTER_RIGHT, &game->img_wh, &game->img_wh);
	if (game->player_x > (game->total_col / 2))
	{
		game->wiz_img = game->character[0];
		game->direction = 'R';
	}
	else if (game->player_x <= (game->total_col / 2))
	{
		game->wiz_img = game->character[1];
		game->direction = 'L';
	}
}
