/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:56 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/05 12:22:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	new_position(int x, int y, t_game *game, t_position *pos)
{
	(void)pos;
	game->pacman->x = x;
	game->pacman->y = y;
}
