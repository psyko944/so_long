/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:22:20 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/19 18:06:36 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 32, y * 32);
}

static void	player_pos_and_draw(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		game->x_player = x;
		game->y_player = y;
		img_draw(game, game->img_player, x, y);
	}
	else
	{
		if (game->bonus)
		{
			game->enemy[game->i].x = x;
			game->enemy[game->i].y = y;
			img_draw(game, game->img_enemy, x, y);
			game->i++;
		}
	}
}

static void	door_state(t_game *game)
{
	if (game->items == 0)
	{
		if (game->img_exit != NULL)
			mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"assets/open_door.xpm", &game->img_width, &game->img_length);
	}
}

static void	finish_game(t_game *game)
{
	game->i = 0;
	if (game->endgame)
	{
		if (!game->won)
			ft_printf("Game Over\n");
		else
			ft_printf("Bravo tu as gagner la partie\n");
		free_game(game);
	}
	if (game->bonus == 1)
		display_move(game);
}

int	map_draw(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	door_state(game);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				img_draw(game, game->img_back, x, y);
			else if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_item, x, y);
			else if (game->map[y][x] == 'E')
				img_draw(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'P' || game->map[y][x] == 'N')
				player_pos_and_draw(game, x, y);
		}
	}
	finish_game(game);
	return (1);
}
