#include "so_long.h"

static void  right_enemy(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy + 1] == '0')
	{
		game->map[game->y_enemy][game->x_enemy] = '0';
		game->x_enemy += 1;
		game->map[game->y_enemy][game->x_enemy] = 'N';
	}
	else if ((game->map[game->y_enemy][game->x_enemy + 1] == '1') ||
			(game->map[game->y_enemy][game->x_enemy + 1] == 'E'))
	{
		game->flag = 1;
		mlx_destroy_image(game->mlx, game->img_enemy);
		game->img_enemy = mlx_xpm_file_to_image
		(game->mlx, "assets/en2.xpm", &game->img_width, &game->img_length);
		if (game->img_enemy == NULL)
			free_xpm(game);
	}
	else if (game->map[game->y_enemy][game->x_enemy + 1] == 'P')
		game->endgame = 1;
}

static void  left_enemy(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy - 1] == '0')
	{
		game->map[game->y_enemy][game->x_enemy] = '0';
		game->x_enemy -= 1;
		game->map[game->y_enemy][game->x_enemy] = 'N';
	}
	else if ((game->map[game->y_enemy][game->x_enemy - 1] == '1') ||
			(game->map[game->y_enemy][game->x_enemy - 1] == 'E'))
	{
		game->flag = 0;
		mlx_destroy_image(game->mlx, game->img_enemy);
		game->img_enemy = mlx_xpm_file_to_image
		(game->mlx, "assets/en1.xpm", &game->img_width, &game->img_length);
		if (game->img_enemy == NULL)
			free_xpm(game);
	}
	else if (game->map[game->y_enemy][game->x_enemy - 1] == 'P')
		game->endgame = 1;
}


int animations(t_game *game)
{
	if (game->clock < 30000)
	{
		game->clock++;
		return (0);
	}
	game->clock = 0;
	if (game->flag == 0)
		right_enemy(game);
	else
		left_enemy(game);
	/*free_enemy(game);
	game->img_enemy = mlx_xpm_file_to_image
	(game->mlx, "assets/en1.xpm", &game->img_width, &game->img_length);
	if (game->img_enemy == NULL)
		free_xpm(game);
	game->animations_enemy = 0;
	}*/
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
