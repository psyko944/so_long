/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:06:10 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/12 19:34:04 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_image(t_game *game)
{
	game->img_back = mlx_xpm_file_to_image
		(game->mlx, "assets/back.xpm", &game->img_width, &game->img_length);
	if (game->img_back == NULL)
		free_xpm(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall2.xpm",
			&game->img_width, &game->img_length);
	if (game->img_wall == NULL)
		free_xpm(game);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/player.xpm", &game->img_width, &game->img_length);
	if (game->img_player == NULL)
		free_xpm(game);
	game->img_item = mlx_xpm_file_to_image
		(game->mlx, "assets/item.xpm", &game->img_width, &game->img_length);
	if (game->img_item == NULL)
		free_xpm(game);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/steel_door.xpm",
			&game->img_width, &game->img_length);
	if (game->img_exit == NULL)
		free_xpm(game);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "assets/en1.xpm",
			&game->img_width, &game->img_length);
	if (game->img_enemy == NULL)
		free_xpm(game);
}

static void	size_window(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->map[0]) * 32;
	while (game->map[i])
		i++;
	game->map_length = i * 32;
}

static void	make_enemy_point(t_game *game)
{
	int	i;

	i = 0;
	game->enemy = malloc(sizeof(t_enemy) * game->n);
	if (game->enemy == NULL)
		return ;
	while (i < game->n)
	{
		game->enemy[i].y = 0;
		game->enemy[i].x = 0;
		if (i % 2)
			game->enemy[i].flag = 0;
		else
			game->enemy[i].flag = 1;
		i++;
	}
}

void	init_game(t_game *game)
{
	if (!check_exit(game))
		return ;
	game->moves = 0;
	game->clock = 0;
	game->endgame = 0;
	game->flag = 0;
	game->i = 0;
	game->enemy = NULL;
	game->img_back = NULL;
	game->img_wall = NULL;
	game->img_item = NULL;
	game->img_player = NULL;
	game->img_enemy = NULL;
	game->img_exit = NULL;
	game->items = game->c;
	if (game->bonus)
		make_enemy_point(game);
	game->mlx = mlx_init();
	size_window(game);
	game->win = mlx_new_window
		(game->mlx, game->map_width, game->map_length, "so_long");
	init_image(game);
	map_draw(game);
	hook(game);
	mlx_loop(game->mlx);
}
