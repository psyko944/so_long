/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:55:54 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/08 19:56:43 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	algo2(char **arr, int y, int x, t_algo *class)
{
	if (arr[y][x - 1] == 'E' || arr[y][x + 1] == 'E')
		class->e = 1;
	else if (arr[y + 1][x] == 'E' || arr[y - 1][x] == 'E')
		class->e = 1;
	else if (arr[y][x] == 'C')
	{
		arr[y][x] = '0';
		--class->items;
	}
}

static void	algo(char **arr, int y, int x, t_algo *class)
{
	algo2(arr, y, x, class);
	if (arr[y][x - 1] != '1' && arr[y][x - 1] != 'E')
	{
		arr[y][x] = '1';
		algo(arr, y, x - 1, class);
	}
	if (arr[y + 1][x] != '1' && arr[y + 1][x] != 'E')
	{
		arr[y][x] = '1';
		algo(arr, y + 1, x, class);
	}
	if (arr[y - 1][x] != '1' && arr[y - 1][x] != 'E')
	{
		arr[y][x] = '1';
		algo(arr, y - 1, x, class);
	}
	if (arr[y][x + 1] != '1' && arr[y][x + 1] != 'E')
	{
		arr[y][x] = '1';
		algo(arr, y, x + 1, class);
	}
}

static char	**cpy_map(char **map)
{
	char	**cpy;
	int		y;

	y = 0;
	while (map[y])
		y++;
	cpy = NULL;
	cpy = malloc(sizeof(char *) * (y + 1));
	if (cpy == NULL)
		return (NULL);
	y = 0;
	while (map[y])
	{
		cpy[y] = ft_strdup(map[y]);
		if (cpy[y] == NULL)
			free_cpy(cpy, y, map);
		y++;
	}
	cpy[y] = NULL;
	return (cpy);
}

static void	runtime(t_algo *class, t_game *game, char **map_cpy)
{
	int	x;
	int	y;

	y = -1;
	class->items = game->c;
	class->e = 0;
	map_cpy = cpy_map(game->map);
	while (map_cpy[++y])
	{
		x = -1;
		while (map_cpy[y][++x])
		{
			if (map_cpy[y][x] == 'P')
				algo(map_cpy, y, x, class);
		}
	}
	free_map(map_cpy);
}

int	check_exit(t_game *game)
{
	t_algo	class;
	char	**map_cpy;

	map_cpy = NULL;
	runtime(&class, game, map_cpy);
	if (class.e == 1 && class.items == 0)
		return (1);
	ft_printf("there is no path to the exit\n");
	return (0);
}
