/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:18:03 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/15 19:21:52 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static void	algo(char **arr, int y, int x, int *e, int items)
{
	ft_printf("%d\n",items);
	if (arr[y][x] == 'E')
		*e = 1;
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

	e = 0;
	y = -1;
	map_cpy = cpy_map(game->map);
	while (map_cpy[++y])
	{
		x = -1;
		while (map_cpy[y][++x])
		{
			if (map_cpy[y][x] == 'P')
				algo(map_cpy, y, x, &e, game->items);
		}
	}
	free_map(map_cpy);
	if (e == 1)
		return (1);
	ft_printf("there is no path to the exit\n");
	return (0);
}
*/
static int	check_args(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	i--;
	if (av[i] == 'r' && av[i - 1] == 'e'
		&& av[i - 2] == 'b' && av[i - 3] == '.')
		return (1);
	ft_printf(
		"Error\nwrong formats of maps : %s good format is : ./so_long *.ber\n",
		av);
	return (0);
}

/*static void	print_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		ft_printf("%s\n", map[i]);
}*/

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	if (!envp[0])
		exit(0);
	if (ac == 2)
	{
		game.map = get_map(av[1]);
		if (game.map == NULL)
			return (0);
		//print_map(game.map);
		if (check_args(av[1]) && check(&game))
			init_game(&game);
		if (game.map)
			free_map(game.map);
	}
	else
		ft_printf("Error\nwrong number of arguments\n");
	return (0);
}
