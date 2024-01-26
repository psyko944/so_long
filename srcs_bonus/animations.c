/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:53:05 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/20 14:53:08 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_enemy(t_game *game, t_enemy *enemy)
{
	enemy->flag = 1;
	mlx_destroy_image(game->mlx, game->img_enemy);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"assets/en2.xpm", &game->img_width, &game->img_length);
	if (game->img_enemy == NULL)
		free_xpm(game);
}

static void	right_enemy(t_game *game, t_enemy *enemy)
{
	if (game->map[enemy->y][enemy->x + 1] == '0')
	{
		game->map[enemy->y][enemy->x] = '0';
		enemy->x += 1;
		game->map[enemy->y][enemy->x] = 'N';
	}
	else if (game->map[enemy->y][enemy->x + 1] == 'C')
		free_enemy(game, enemy);
	else if ((game->map[enemy->y][enemy->x + 1] == '1') ||
			(game->map[enemy->y][enemy->x + 1] == 'E'))
		free_enemy(game, enemy);
	else if (game->map[enemy->y][enemy->x + 1] == 'P')
		game->endgame = 1;
}

static void	left_enemy(t_game *game, t_enemy *enemy)
{
	if (game->map[enemy->y][enemy->x - 1] == '0')
	{
		game->map[enemy->y][enemy->x] = '0';
		enemy->x -= 1;
		game->map[enemy->y][enemy->x] = 'N';
	}
	else if ((game->map[enemy->y][enemy->x - 1] == '1') ||
			(game->map[enemy->y][enemy->x - 1] == 'E') ||
				(game->map[enemy->y][enemy->x - 1] == 'C'))
	{
		enemy->flag = 0;
		mlx_destroy_image(game->mlx, game->img_enemy);
		game->img_enemy = mlx_xpm_file_to_image(game->mlx,
				"assets/en1.xpm", &game->img_width, &game->img_length);
		if (game->img_enemy == NULL)
			free_xpm(game);
	}
	else if (game->map[enemy->y][enemy->x - 1] == 'P')
		game->endgame = 1;
}

int	animations(t_game *game)
{
	int	i;

	i = 0;
	if (game->clock < 30000)
	{
		game->clock++;
		return (0);
	}
	game->clock = 0;
	while (i < game->n)
	{
		if (game->enemy[i].flag == 0)
			right_enemy(game, &game->enemy[i]);
		else
			left_enemy(game, &game->enemy[i]);
		i++;
	}
	map_draw(game);
	return (0);
}

void	display_move(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, WHITE, "MOVES : ");
	mlx_string_put(game->mlx, game->win, 70, 20, WHITE, str);
	free(str);
}
