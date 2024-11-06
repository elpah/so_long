/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:21:14 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/03 00:20:52 by elpah            ###   ########.fr       */
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

void allocate_map(t_game *game, int line_count);
void find_player_position(t_game *game_map);
void free_map(t_game *game);
void set_row_col(t_game *game);
void flood_fill(t_game *game, int x, int y, bool **visited);
bool **create_visited_array(int rows, int cols);
bool all_collectibles_reachable(t_game *game, bool **visited);
int check_collectibles(t_game *game);
void fill_map(char **av, t_game *game, int count);
int is_valid_file(char *str);
int map_is_valid(t_game *game);
int only_valid_chars(char **rec);
int check_characters(t_game *game, char c);
int count_chars(char **rec, char c);
void load_player_and_collectibles(t_game *game);
void load_wall_door(t_game *game);
void init_map(t_game *game);
void ft_put_img(t_game *game, void *img, int row, int col);
int free_destroy(t_game *game);
void change_position(t_game *game, int row, int col);
void is_exit(t_game *game, int row, int col);
void launch_graphics(t_game *game);
void check_exit(t_game *game);
void move_player(t_game *game, int row, int col);
void key_hook2(int keycode, t_game *game);
int ft_key_hook(int keycode, t_game *game);
void init_game_variables(t_game *game);
int ft_is_rectangle(char **rec);
int ft_surrounded_by_1(char **rec);

#endif
