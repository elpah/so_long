/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:21:14 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/03 00:17:04 by elpah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_game
{
	char **map;
	int player_x;
	int player_y;
	int total_rows;
	int total_col;
	char direction;
	char last_pos;
	char *addr;

	void *mlx;
	void *mlx_win;
	void *wiz_img;
	void *door[2];
	void *character[2];
	void *floor;
	void *wall;
	void *treasure;
	int steps;
	int gate;
	int img_wh;
	int collectibles;
	int collectibles_count;
} t_game;

#endif
