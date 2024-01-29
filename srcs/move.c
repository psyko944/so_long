/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:57:40 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/19 18:28:40 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	swap_h_moves(t_game *game, int flag)
{
	static int	flag_l = 0;

	if (flag == 1 && flag_l == 1)
		parse_move(game);
	else if (flag == 1 && flag_l == 0)
		parse_move2(game);
	else if (flag == 2)
		parse_move3(game, &flag_l);
	else if (flag == 3)
		parse_move4(game, &flag_l);
	else if (flag == 4 && flag_l == 1)
		parse_move5(game);
	else
	{
		if (game->img_player != NULL)
			mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
				&game->img_width, &game->img_length);
		if (game->img_player == NULL)
			free_xpm(game);
	}
}

void	up_move(t_game *game)
{
	if (game->map[game->y_player - 1][game->x_player] == 'E'
		&& game->items == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->y_player -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->endgame = 1;
		game->won = 1;
	}
	else if (game->map[game->y_player - 1][game->x_player] == 'E'
		|| game->map[game->y_player - 1][game->x_player] == '1')
		return ;
	else if (game->map[game->y_player - 1][game->x_player] == 'N')
		game->endgame = 1;
	else
	{
		game->map[game->y_player][game->x_player] = '0';
		game->y_player -= 1;
		if (game->map[game->y_player][game->x_player] == 'C')
			game->items -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		swap_h_moves(game, 1);
	}
	ft_printf("moves : %d\n", ++(game->moves));
	map_draw(game);
}

void	down_move(t_game *game)
{
	if (game->map[game->y_player + 1][game->x_player] == 'E'
		&& game->items == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->y_player += 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->endgame = 1;
		game->won = 1;
	}
	else if (game->map[game->y_player + 1][game->x_player] == 'E'
		|| game->map[game->y_player + 1][game->x_player] == '1')
		return ;
	else if (game->map[game->y_player + 1][game->x_player] == 'N')
		game->endgame = 1;
	else
	{
		game->map[game->y_player][game->x_player] = '0';
		game->y_player += 1;
		if (game->map[game->y_player][game->x_player] == 'C')
			game->items -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		swap_h_moves(game, 4);
	}
	ft_printf("moves : %d\n", ++(game->moves));
	map_draw(game);
}

void	right_move(t_game *game)
{
	if (game->map[game->y_player][game->x_player + 1] == 'E'
		&& game->items == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->x_player += 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->endgame = 1;
		game->won = 1;
	}
	else if (game->map[game->y_player][game->x_player + 1] == 'E'
		|| game->map[game->y_player][game->x_player + 1] == '1')
		return ;
	else if (game->map[game->y_player][game->x_player + 1] == 'N')
		game->endgame = 1;
	else
	{
		game->map[game->y_player][game->x_player] = '0';
		game->x_player += 1;
		if (game->map[game->y_player][game->x_player] == 'C')
			game->items -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		swap_h_moves(game, 3);
	}
	ft_printf("moves : %d\n", ++(game->moves));
	map_draw(game);
}

void	left_move(t_game *game)
{
	if (game->map[game->y_player][game->x_player - 1] == 'E'
		&& game->items == 0)
	{
		game->map[game->y_player][game->x_player] = '0';
		game->x_player -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->endgame = 1;
		game->won = 1;
	}
	else if (game->map[game->y_player][game->x_player - 1] == 'E'
		|| game->map[game->y_player][game->x_player - 1] == '1')
		return ;
	else if (game->map[game->y_player][game->x_player - 1] == 'N')
		game->endgame = 1;
	else
	{
		game->map[game->y_player][game->x_player] = '0';
		game->x_player -= 1;
		if (game->map[game->y_player][game->x_player] == 'C')
			game->items -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		swap_h_moves(game, 2);
	}
	ft_printf("moves : %d\n", ++(game->moves));
	map_draw(game);
}
