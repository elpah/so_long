/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpah <elpah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:20:19 by eobeng            #+#    #+#             */
/*   Updated: 2024/11/03 00:23:40 by elpah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_is_rectangle(char **rec)
{
	int first_line;
	int x;

	x = 0;
	if (!rec || !rec[0])
		return (0);
	first_line = ft_strlen(rec[0]);
	x++;
	while (rec[x] != NULL)
	{
		if (ft_strlen(rec[x]) != (size_t)first_line)
			return (0);
		x++;
	}
	return (1);
}

int ft_all_ones(char *rec_row)
{
	int i;

	i = 0;
	while (rec_row[i + 1] != '\0')
	{
		if (rec_row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int ft_surrounded_by_1(char **rec)
{
	int x;
	int len;

	if (!rec || !rec[0])
		return (0);
	len = ft_strlen(rec[0]);
	if (!ft_all_ones(rec[0]))
		return (0);
	x = 1;
	while (rec[x])
	{
		if (rec[x][0] != '1' || rec[x][len - 1] != '1')
			return (0);
		x++;
	}
	if (!ft_all_ones(rec[x - 1]))
		return (0);
	return (1);
}

int count_chars(char **rec, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (rec[i] != NULL)
	{
		j = 0;
		while (rec[i][j] != '\0')
		{
			if (rec[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int check_characters(t_game *game, char c)
{
	int i;
	int j;
	char **map;

	map = game->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
