/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/27 14:30:50 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_img(t_game *game)
{
	mlx_destroy_image(game->id, game->player);
	mlx_destroy_image(game->id, game->water);
	mlx_destroy_image(game->id, game->wall);
	mlx_destroy_image(game->id, game->fish);
	mlx_destroy_image(game->id, game->exit);
}

int	close_game(t_game *game)
{
	ft_free_img(game);
	mlx_clear_window(game->id, game->w_id);
	mlx_destroy_window(game->id, game->w_id);
	mlx_destroy_display(game->id);
	free(game->id);
	ft_free_splitted_map(game->map);
	free(game->pacman);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int key, t_game *game)
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
	return (0);
}

void	ft_init_game(t_game *game, t_layout *layout)
{
	int	size;

	size = SIZE;
	game->height = layout->rows;
	game->width = layout->columns;
	game->pacman = malloc(sizeof(t_player));
	game->nb_collectibles = layout->collectibles;
	game->collected = 0;
	game->id = mlx_init();
	game->w_id = mlx_new_window(game->id, game->width * size, \
	game->height * size, "help");
	game->wall = mlx_xpm_file_to_image(game->id, \
	"./img/wall.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->id, \
	"./img/dolphin.xpm", &size, &size);
	game->water = mlx_xpm_file_to_image(game->id, \
	"./img/water.xpm", &size, &size);
	game->fish = mlx_xpm_file_to_image(game->id, \
	"./img/fish.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->id, \
	"./img/exit.xpm", &size, &size);
	game->map = layout->map;
}

int	main(int ac, char **av)
{
	t_game		game;
	t_layout	layout;

	if (ac == 2)
	{
		check_map(av[1], &layout);
		ft_init_game(&game, &layout);
		ft_init_map(&game, 1);
		ft_put_pac(&game);
		mlx_loop_hook(game.id, ft_update, (void*)&game);
		mlx_hook(game.w_id, 17, 0, close_game, (void*)&game);
		mlx_key_hook(game.w_id, key_hook, (void*)&game);
		mlx_loop(game.id);
	}
}
