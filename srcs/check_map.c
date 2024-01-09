/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:11:26 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/15 18:12:18 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	is_valid_c(char c)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'C' && c != 'P')
		return (0);
	return (1);
}

static int	is_rectangular(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_correct_middle_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	while (line[i + 2])
	{
		i++;
		if (!is_valid_c(line[i]))
			return (0);
		if (line[i] == 'P')
			game->p += 1;
		if (line[i] == 'E')
			game->e += 1;
		if (line[i] == 'C')
			game->c += 1;
	}
	i++;
	if (line[i] != '1')
		return (0);
	return (1);
}

static int	check_wall(char *wall_line)
{
	int	i;

	i = -1;
	while (wall_line[++i])
		if (wall_line[i] != '1')
			return (0);
	return (1);
}

int	check(t_game *game)
{
	int	i;

	i = 0;
	game->e = 0;
	game->p = 0;
	game->c = 0;
	if (!is_rectangular(game->map))
		return (0);
	if (!check_wall(game->map[0]))
		return (0);
	i++;
	while (game->map[i])
	{
		if (!is_correct_middle_line(game->map[i], game))
			return (0);
		if (game->map[i + 1] == NULL)
			if (!check_wall(game->map[i]))
				return (0);
		i++;
	}
	if (game->p != 1 || game->e == 0 || game->c == 0)
		return (0);
	return (1);
}
