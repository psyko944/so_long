/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:23:08 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/16 19:46:10 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_move(t_game *game)
{
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player_cur_l.xpm", &game->img_width, &game->img_length);
	if (game->img_player == NULL)
		free_xpm(game);
}

void	parse_move2(t_game *game)
{
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/player.xpm", &game->img_width, &game->img_length);
	if (game->img_player == NULL)
		free_xpm(game);
}

void	parse_move3(t_game *game, int *flag_l)
{
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/player_l.xpm", &game->img_width, &game->img_length);
	*flag_l = 1;
	if (game->img_player == NULL)
		free_xpm(game);
}

void	parse_move4(t_game *game, int *flag_l)
{
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	*flag_l = 0;
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/player_r.xpm", &game->img_width, &game->img_length);
	if (game->img_player == NULL)
		free_xpm(game);
}

void	parse_move5(t_game *game)
{
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player_cur_l.xpm", &game->img_width, &game->img_length);
	if (game->img_player == NULL)
		free_xpm(game);
}
