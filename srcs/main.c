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

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	if (!envp[0])
		exit(0);
	if (ac == 2)
	{
		if (ft_strnstr(av[0], "bonus", ft_strlen(av[0])))
			game.bonus = 1;
		else
			game.bonus = 0;
		game.map = get_map(av[1]);
		game.won = 0;
		if (game.map == NULL)
			return (0);
		if (check_args(av[1]) && check(&game))
			init_game(&game);
		else
			ft_printf("invalid map\n");
		if (game.map)
			free_map(game.map);
	}
	else
		ft_printf("Error\nwrong number of arguments\n");
	return (0);
}
