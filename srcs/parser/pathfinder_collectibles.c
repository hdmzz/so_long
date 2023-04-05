/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_collectibles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:36 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/05 12:22:23 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// static void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_printf("%s\n", map[i]);
// 		i++;
// 	}
// }

static void	flood(int x, int y, t_layout *layout)
{
	if (layout->map_dup[y][x] == '1' || layout->map_dup[y][x] == '3' \
		|| layout->map_dup[y][x] == 'E')
		return ;
	layout->map_dup[y][x] = '3';
	flood(x, y + 1, layout);
	flood(x, y - 1, layout);
	flood(x - 1, y, layout);
	flood(x + 1, y, layout);
	return ;
}

static int	check_collectibles(t_layout *layout)
{
	int	i;

	i = 0;
	while (layout->map_dup[i])
	{
		if (ft_strchr(layout->map_dup[i], 'C'))
			return (0);
		i++;
	}
	return (1);
}

int	pathfinder_collectibles(t_layout *layout)
{
	int	is_path;
	int	nb_collec;

	nb_collec = layout->collectibles;
	layout->map_dup = path_clone(layout->map);
	layout->nb_moves_max = (layout->rows * layout->columns) * 2;
	layout->nb_moves = 0;
	flood(layout->player_position->x, layout->player_position->y, layout);
	is_path = check_collectibles(layout);
	ft_free_splitted_map(layout->map_dup);
	layout->collectibles = nb_collec;
	return (is_path);
}
