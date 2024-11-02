/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:21:14 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/03 00:20:02 by elpah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

// # include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
// # include <mlx.h>

#define SIZE 80
#define TEXTURE_WALL "textures/xpm/wall.xpm"
#define TEXTURE_FLOOR "textures/xpm/floor.xpm"
#define TEXTURE_CHARACTER_LEFT "textures/xpm/wiz_left.xpm"
#define TEXTURE_CHARACTER_RIGHT "textures/xpm/wiz_right.xpm"
#define TEXTURE_DOOR_OPEN "textures/xpm/door2.xpm"
#define TEXTURE_DOOR_CLOSE "textures/xpm/door1.xpm"
#define TEXTURE_COLLECTIBLE "textures/xpm/herb.xpm"

#define BUFFER_SIZE 1024

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

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
