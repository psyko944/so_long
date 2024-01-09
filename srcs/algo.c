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

static void	algo(char **arr, int y, int x, int *e, int *items)
{
	if (arr[y][x] == 'E')
		*e = 1;
	else if (arr[y][x] == 'C')
		ft_printf("%d\n", --*items);
	if (arr[y][x - 1] != '1')
	{
		arr[y][x] = '1';
		algo(arr, y, x - 1, e, items);
	}
	if (arr[y + 1][x] != '1')
	{
		arr[y][x] = '1';
		algo(arr, y + 1, x, e, items);
	}
	if (arr[y - 1][x] != '1')
	{
		arr[y][x] = '1';
		algo(arr, y - 1, x, e, items);
	}
	if (arr[y][x + 1] != '1')
	{
		arr[y][x] = '1';
		algo(arr, y, x + 1, e, items);
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

int	check_exit(t_game *game)
{
	int		x;
	int		y;
	int		e;
	char	**map_cpy;
	int		items;

	e = 0;
	y = -1;
	items = game->c;
	map_cpy = cpy_map(game->map);
	while (map_cpy[++y])
	{
		x = -1;
		while (map_cpy[y][++x])
		{
			if (map_cpy[y][x] == 'P')
				algo(map_cpy, y, x, &e, &items);
		}
	}
	free_map(map_cpy);
	ft_printf("items = %d\n", items);
	if (e == 1 &&  items == 0)
		return (1);
	ft_printf("there is no path to the exit\n");
	return (0);
}
