/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:16:26 by mekherbo          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:57 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stddef.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>

//      struct for algo map     //
typedef struct s_algo
{
	int	e;
	int	items;
	int	x;
	int	y;
}	t_algo;

//      struct for coordiantes of enemy     //
typedef struct s_enemy
{
	int	flag;
	int	y;
	int	x;
}	t_enemy;

//      struct of game       //
typedef struct s_game
{
	void	*mlx;
	void	*img;
	void	*win;
	void	*img_back;
	void	*img_wall;
	void	*img_player;
	void	*img_item;
	void	*img_enemy;
	void	*img_exit;
	char	**map;
	int		map_length;
	int		map_width;
	int		img_length;
	int		img_width;
	int		x_player;
	int		y_player;
	int		items;
	int		endgame;
	int		won;
	int		moves;
	t_enemy	*enemy;
	int		e;
	int		c;
	int		flag;
	int		clock;
	int		bonus;
	int		p;
	int		n;
	int		i;
}	t_game;

//       Colors         //
# define WHITE 0xffffff
# define BLACK 0x0
# define RED 0xff0000
# define GREEN 0xff00
# define YELLOW 0xffff00
# define ORANGE 0xffa500
# define BLUE 0x2F32FF
# define DARK_BLUE 0x2F327A
# define LIGHT_GRAY 0xd3d3d3

//      so_long  functions         //
char	**get_map(char *filename);
void	free_map(char **tab);
int		check(t_game *game);
void	init_game(t_game *game);
void	free_xpm(t_game *game);
void	free_cpy(char **map, int y, char **first);
int		free_game(t_game *game);
int		map_draw(t_game *game);
void	hook(t_game *game);
void	up_move(t_game *game);
void	left_move(t_game *game);
void	down_move(t_game *game);
void	right_move(t_game *game);
int		check_exit(t_game *game);

//      functions for swap xpm player  //
void	parse_move(t_game *game);
void	parse_move2(t_game *game);
void	parse_move3(t_game *game, int *flag_l);
void	parse_move4(t_game *game, int *flag_l);
void	parse_move5(t_game *game);

//      bonus functions           //
void	display_move(t_game *game);
int		animations(t_game *game);

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

#endif
