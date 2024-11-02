/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:37:01 by eobeng            #+#    #+#             */
/*   Updated: 2024/10/26 19:45:01 by eobeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_file(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (ft_strncmp(str + (len - 4), ".ber", 4) != 0)
		return (0);
	return (1);
}

int	only_valid_chars(char **rec)
{
	int	i;
	int	j;

	i = 0;
	while (rec[i] != NULL)
	{
		j = 0;
		while (rec[i][j] != '\0')
		{
			if (rec[i][j] != 'C' && rec[i][j] != 'E' &&
				rec[i][j] != 'P' && rec[i][j] != '0' &&
				rec[i][j] != '1')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_valid_chars(t_game *game)
{
	if (!check_characters(game, 'C')
		|| !check_characters(game, 'E')
		|| !check_characters(game, 'P')
		|| !check_characters(game, '1'))
	{
		return (0);
	}
	return (1);
}

int	map_is_valid(t_game *game)
{
	char	**map;

	map = game->map;
	if (!ft_is_rectangle(map)
		|| !ft_surrounded_by_1(map)
		|| !ft_valid_chars(game)
		|| !only_valid_chars(map))
	{
		ft_printf("Error\n:Map is not valid\n");
		return (0);
	}
	if ((count_chars(map, 'P') != 1) || (count_chars(map, 'E') != 1))
	{
		ft_printf("Error\n: Duplicate Character or Exit found in map\n");
		return (0);
	}
	return (1);
}
