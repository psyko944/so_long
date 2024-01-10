/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:14:45 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/10 20:39:06 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_xpm(t_game *game)
{
	free_map(game->map);
	if (game->img_back != NULL)
		mlx_destroy_image(game->mlx, game->img_back);
	if (game->img_wall != NULL)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_exit != NULL)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_item != NULL)
		mlx_destroy_image(game->mlx, game->img_item);
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_enemy != NULL)
		mlx_destroy_image(game->mlx, game->img_enemy);
	ft_printf("Error\n xpm file\n");
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_cpy(char **map, int y, char **first)
{
	y = y - 1;
	while (y >= 0)
		free(map[y--]);
	free(map);
	free_map(first);
	exit(0);
}

int	free_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_back);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_item);
	mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_enemy != NULL)
		mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
