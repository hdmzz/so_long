/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/14 22:43:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		close_game(t_game *game)
{
	mlx_clear_window(game->id, game->w_id);
	mlx_destroy_window(game->id, game->w_id);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_move(t_game *g, int direction)
{
	if (direction == KEY_A)
		g->pacman->x -= 1 * 32;
	if (direction == KEY_W)
		g->pacman->y -= 1 * 32;
	if (direction == KEY_D)
		g->pacman->x += 1 * 32;
	if (direction == KEY_S)
		g->pacman->y += 1 * 32;
}

int		key_hook(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		close_game(game);
	if (key == KEY_A)
		ft_move(game, key);
	if (key == KEY_D)
		ft_move(game, key);
	if (key == KEY_S)
		ft_move(game, key);
	if (key == KEY_W)
		ft_move(game, key);
}

void	ft_init_map(t_game *game, int pac_pos)
{
	int	x;
	int	y;
	int	size;

	size = 32;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ( game->map[y][x] == '1')
				mlx_put_image_to_window(game->id, game->w_id, game->wall, x * size, y * size);
			if (pac_pos && game->map[y][x] == 'P')
				new_position(x * size, y * size, game);
			x++;
		}
		y++;
	}
}

void	ft_put_pac(t_game *game)
{
	int	size;

	size = 32;
	mlx_put_image_to_window(game->id, game->w_id, game->pacman->img, game->pacman->x, game->pacman->y);
}

int	ft_update(t_game *game)
{
	ft_init_map(game, 0);
	ft_put_pac(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_layout	layout;
	int			size;
	char *map[7] = { "11111111", "10010001", "10000P01", "11000001","100000E1", "11111111", NULL};//uniquement pour phase de develeoppement
	
	size = 32; 

	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, 700, 500, "help");
	game.wall = mlx_xpm_file_to_image(mlx, "../img/wall.xpm", &size, &size);
	game.pacman = malloc(sizeof(t_player));
	game.pacman->img = mlx_xpm_file_to_image(mlx, "../img/pacman.xpm", &size, &size);
	game.map = map;
	game.id = mlx;
	game.w_id = mlx_win;
	ft_init_map(&game, 1);
	ft_put_pac(&game);
	mlx_loop_hook(game.id, ft_update, (void*)&game);
	mlx_hook(game.w_id, 17, 0, close_game, (void*)&game);
	mlx_key_hook(mlx_win, key_hook, (void*)&game);
	mlx_loop(game.id);
}
