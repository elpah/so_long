/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:18:03 by eobeng            #+#    #+#             */
/*   Updated: 2024/07/31 14:42:18 by eobeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptrdest;
	char	*ptrsrc;
	size_t	i;

	if (!dest && !src)
	{
		return (dest);
	}
	i = 0;
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}

static void	ft_free(char **str)
{
	if (str[0])
	{
		free(str[0]);
		str[0] = NULL;
	}
}

static int	read_and_append(int fd, char **buf, char *cup)
{
	int		bytes;
	char	*temp;

	bytes = read(fd, cup, BUFFER_SIZE);
	if (bytes <= 0)
		return (bytes);
	cup[bytes] = '\0';
	temp = ft_strjoin(*buf, cup);
	if (!temp)
		return (-1);
	ft_free(buf);
	*buf = temp;
	return (bytes);
}

static char	*create_line_and_update_buffer(char **buf, char *newline_pos)
{
	char	*line;
	char	*temp;
	int		length_to_copy;

	if (newline_pos)
	{
		length_to_copy = newline_pos - *buf + 1;
		line = (char *)malloc(length_to_copy + 1);
		if (!line)
		{
			ft_free(buf);
			return (NULL);
		}
		ft_memcpy(line, *buf, length_to_copy);
		line[length_to_copy] = '\0';
		temp = ft_strdup(newline_pos + 1);
		ft_free(buf);
		*buf = temp;
	}
	else
	{
		line = ft_strdup(*buf);
		ft_free(buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*cup;
	char		*line;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
		buf = ft_strdup("");
	cup = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!cup)
		return (NULL);
	while ((ft_strchr(buf, '\n')) == NULL)
	{
		bytes = read_and_append(fd, &buf, cup);
		if (bytes <= 0)
			break ;
	}
	ft_free(&cup);
	if (bytes == -1 || (!(ft_strchr(buf, '\n')) && buf[0] == '\0'))
		return (ft_free(&buf), NULL);
	line = create_line_and_update_buffer(&buf, ft_strchr(buf, '\n'));
	return (line);
}
