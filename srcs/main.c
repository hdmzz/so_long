/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/18 23:54:52 by hdamitzi         ###   ########.fr       */
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

int		key_hook(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		close_game(game);
	if (key == KEY_A)
		ft_move_left(game);
	if (key == KEY_D)
		ft_move_right(game);
	if (key == KEY_S)
		ft_move_down(game);
	if (key == KEY_W)
		ft_move_up(game);
}

void	ft_init_map(t_game *game, int pac_pos)
{
	int	x;
	int	y;
	t_position	position;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ( game->map[y][x] == '1')
				mlx_put_image_to_window(game->id, game->w_id, game->wall, x * SIZE, y * SIZE);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->id, game->w_id, game->water, x * SIZE, y * SIZE);
			if (pac_pos && game->map[y][x] == 'P')
				new_position(x, y, game, &position);
			x++;
		}
		y++;
	}
	game->pacman->curr_position = &position;
}

void	ft_put_pac(t_game *game)
{
	mlx_put_image_to_window(game->id, game->w_id, game->pacman->img, game->pacman->x * SIZE, game->pacman->y * SIZE);
}

void	ft_put_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ( game->map[y][x] == '1')
				mlx_put_image_to_window(game->id, game->w_id, game->wall, x * SIZE, y * SIZE);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->id, game->w_id, game->water, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

int	ft_update(t_game *game)
{
	ft_put_map(game);
	ft_put_pac(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_layout	layout;
	int size = SIZE;
	char *map = { "1111111111\n1000010001\n1001110111\n1000P00111\n1111111111"};//uniquement pour phase de develeoppement
	//char **lay = check_map(av[1], &layout);
	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, 500, 500, "help");
	game.wall = mlx_xpm_file_to_image(mlx, "../img/wall.xpm", &size, &size);
	game.pacman = malloc(sizeof(t_player));
	game.pacman->img = mlx_xpm_file_to_image(mlx, "../img/pacman.xpm", &size, &size);
	game.water = mlx_xpm_file_to_image(mlx, "../img/water.xpm", &size, &size);
	game.map = ft_split(map, '\n');
	game.id = mlx;
	game.w_id = mlx_win;
	ft_init_map(&game, 1);
	ft_printf("%d\n", game.pacman->curr_position->x);
	ft_put_pac(&game);
	mlx_loop_hook(game.id, ft_update, (void*)&game);
	mlx_hook(game.w_id, 17, 0, close_game, (void*)&game);
	mlx_key_hook(mlx_win, key_hook, (void*)&game);
	mlx_loop(game.id);
}
