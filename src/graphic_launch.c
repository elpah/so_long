/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:21:14 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/07 16:13:18 by eobeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	launch_graphics(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SIZE * game->total_col,
			SIZE * game->total_rows, "HERB HUNTER");
	game->last_pos = '0';
	load_player_and_collectibles(game);
	load_wall_door(game);
	init_map(game);
	ft_printf("Steps: %i\tcollectibles: %i/%i\n",
		game->steps, game->collectibles_count, game->collectibles);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, free_destroy, game);
	mlx_loop(game->mlx);
}
