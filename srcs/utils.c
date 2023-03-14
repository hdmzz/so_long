/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:56 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/14 17:06:57 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	new_position(int x, int y, t_game *game)
{
	game->pacman->x = x;
	game->pacman->y = y;
	ft_printf("first x = %d\n", game->pacman->x);
}
