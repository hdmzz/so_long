/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:31:35 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/19 03:41:47 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (legal_move(game, x - 1, y))
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->pacman->x = x - 1;
	}
}

void	ft_move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (legal_move(game, x + 1, y))
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->pacman->x = x + 1;
	}
}

void	ft_move_up(t_game *game)
{
	int			x;
	int			y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (legal_move(game, x, y - 1))
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->pacman->y = y - 1;
	}
}

void	ft_move_down(t_game *game)
{
	int			x;
	int			y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (legal_move(game, x, y + 1))
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->pacman->y = y + 1;
	}
}
