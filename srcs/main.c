/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/13 04:45:33 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_game(t_game *game)
{
	mlx_clear_window(game->id, game->w_id);
	mlx_destroy_window(game->id, game->w_id);
	exit(EXIT_SUCCESS);
}

int		key_hook(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		close_game(game);
	if (key == KEY_A)
		ft_printf("left");
	if (key == KEY_D)
		ft_printf("right");
	if (key == KEY_S)
		ft_printf("down");
	if (key == KEY_W)
		ft_printf("up");
}

// void	ft_new_game(t_layout *lay, t_game *game, char **map)
// {
// 	mlx_key_hook(game->w_id, key_hook, (void*)game);
// }

// void	init_game(t_layout *lay, t_game *game, char **map)
// {
// 	game->id = mlx_init();
// 	game->w_id = mlx_new_window(game->id, 32, 32 * 80, "so_long");
// 	game->backgrnd = lay;
// 	game->moves_nbr = 0;
// 	game->map = map;
// 	game->width = lay->columns;
// 	game->height = lay->rows;
// 	game->nxt_dir = 0;
// 	//ft_new_game(lay, game, map);
// }

// void	so_long(char *file)
// {
// 	t_layout	map_lay;
// 	t_game		game;
// 	char		**map;
// 	void		*id;

// 	map = check_map(file, &map_lay);
// 	init_game(&map_lay, &game, map);
// }

// void	ft_put_map(t_game *game,int x, int y)
// {
// 	if (game->map[y][x] ==  "1")
// 		mlx_
// }

void	ft_init_map(t_game *game)
{
	int	x;//ombre de colonnes donc axes x
	int	y;//ombre de ligne donc axe y
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
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->id, game->w_id, game->pacman, x * size, y * size);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game		game;
	t_layout	layout;
	int			size;
	char *map[7] = { "11111111", "10010001", "1P000001", "11000001","100000E1", "11111111", NULL};//uniquement pour phase de develeoppement
	
	size = 32;

	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, 700, 500, "help");
	game.wall = mlx_xpm_file_to_image(mlx, "../img/wall.xpm", &size, &size);
	game.pacman = mlx_xpm_file_to_image(mlx, "../img/pacman.xpm", &size, &size);
	game.map = map;
	game.id = mlx;
	game.w_id = mlx_win;
	ft_init_map(&game);
	mlx_key_hook(mlx_win, key_hook, &game);
	mlx_loop(game.id);
}
