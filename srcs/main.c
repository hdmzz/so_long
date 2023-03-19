/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/19 09:45:39 by hdamitzi         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game		game;
	t_layout	layout;
	int size = SIZE;
	char *map = { "1111111111\n10C0010001\n1001110111\n1000P01C11\n1111111111"};//uniquement pour phase de develeoppement
	//char **lay = check_map(av[1], &layout);
	// void *mlx = mlx_init();
	// void *mlx_win = mlx_new_window(mlx, 500, 500, "help");
	// game.pacman = malloc(sizeof(t_player));
	// game.wall = mlx_xpm_file_to_image(mlx, "../img/wall.xpm", &size, &size);
	// game.pacman->img = mlx_xpm_file_to_image(mlx, "../img/pacman.xpm", &size, &size);
	// game.water = mlx_xpm_file_to_image(mlx, "../img/water.xpm", &size, &size);
	// game.collect = mlx_xpm_file_to_image(mlx, "../img/fish.xpm", &size, &size);
	game.map = ft_split(map, '\n');
	pathfinder(&game, 3, 4);
	// game.id = mlx;
	// game.w_id = mlx_win;
	// ft_init_map(&game, 1);
	// ft_printf("%d\n", game.pacman->curr_position->x);
	// ft_put_pac(&game);
	// mlx_loop_hook(game.id, ft_update, (void*)&game);
	// mlx_hook(game.w_id, 17, 0, close_game, (void*)&game);
	// mlx_key_hook(mlx_win, key_hook, (void*)&game);
	// mlx_loop(game.id);
}
