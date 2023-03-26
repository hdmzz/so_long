/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:09:51 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/26 10:55:17 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_rectangular(t_layout *layout)
{
	if (layout->columns > layout->rows || layout->columns < layout->rows)
		return (1);
	return (0);
}

void	player_position(int x, int y, t_layout *layout)
{
	layout->player_position = malloc(sizeof(t_position));//pas free
	if (!layout->player_position)
	{
		free(layout->map);
		error_handler("");
	}
	layout->player_position->x = x;
	layout->player_position->y = y;
	layout->player += 1;
}

void	ft_layout(t_layout *layout)//compte nombre de colonnes de lignes de collec exit player and x y
{//verifie rectangulaire
	t_position	position;
	int	y;
	int	x ;

	y = -1;
	while (layout->map[++y])
	{
		x = -1;
		while (layout->map[y][++x])
		{
			if (layout->map[y][x] == 'C')
				layout->collectibles += 1;
			if (layout->map[y][x] == 'E')
				layout->exit += 1;
			if (layout->map[y][x] == 'P')
				player_position(x, y, layout);
		}
	}
	layout->rows = y;
	layout->columns = x;
	if (!is_rectangular(layout) || !pathfinder(layout))
	{
		ft_free_splitted_map(layout->map);
		error_handler("Map isn't rectangular\n");
	}
	free(layout->player_position);
}
