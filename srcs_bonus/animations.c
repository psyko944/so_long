#include "so_long.h"

static void  enemy_move(t_game *game)
{
	if (game->map[game->])
}

int animations(t_game *game)
{
	if (game->render < 42000)
	{
		game->render++;
		return (0);
	}
	game->render = 0;
	mlx_destroy_image(game->mlx, game->img_enemy);
	free_enemy(game);
	if (game->animations_enemy == 4)
	{
		game->img_enemy = mlx_xpm_file_to_image
		(game->mlx, "assets/en1.xpm", &game->img_width, &game->img_length);
		if (game->img_enemy == NULL)
		free_xpm(game);
		game->animations_enemy = 0;
	}
	map_draw(game);
	game->animations_enemy++;
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
