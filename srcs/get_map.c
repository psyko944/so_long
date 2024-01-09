/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:05:43 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/15 19:21:59 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_fd(int fd, char *filename)
{
	fd = open(filename, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	else
	{
		close(fd);
		exit(1);
	}
	return (fd);
}

char	**get_map(char	*filename)
{
	char	*line;
	char	*join_map;
	char	**map;
	int		fd;

	fd = -1;
	fd = check_fd(fd, filename);
	if (fd == -1)
		return (NULL);
	line = "init";
	join_map = ft_calloc(1, 1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		join_map = ft_strjoin2(join_map, line);
		free(line);
	}
	map = ft_split(join_map, '\n');
	free(join_map);
	close(fd);
	return (map);
}
