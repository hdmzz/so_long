/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:31:01 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/20 12:48:11 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	game->moves_nbr = 0;
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
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->id, game->w_id, game->collect, x * SIZE, y * SIZE);
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
