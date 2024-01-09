/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:12:59 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/15 18:13:41 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		up_move(game);
	else if (keycode == KEY_S)
		down_move(game);
	else if (keycode == KEY_A)
		left_move(game);
	else if (keycode == KEY_D)
		right_move(game);
	display_move(game);
}

static int	key_choice(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_game(game);
	else if (!game->endgame)
		move_player(keycode, game);
	return (0);
}

void	hook(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_choice, game);
	mlx_hook(game->win, 17, 1L << 17, free_game, game);
}
