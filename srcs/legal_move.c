/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legal_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:15:09 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/21 13:30:07 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_collectibles(t_game *game)
{
	if (game->nb_collectibles == game->collected)
		return (1);
	return (0);
}

int	legal_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
		game->collected += 1;
	if (game->map[y][x] == 'E')
	{
		if (check_collectibles(game))
		{
			ft_printf("You Win!!\n");
			close_game(game);
		}
		return (0);
	}
	return (1);
}
