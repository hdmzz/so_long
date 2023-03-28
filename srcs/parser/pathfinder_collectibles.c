/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_collectibles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:36 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/28 22:39:23 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	find_path_collectibles(int x, int y, char **map, int *nb_collectibles)
{
	if (map[y][x] == '1' || map[y][x] == '3')
		return (0);
	if (map[y][x] == 'C')
		*nb_collectibles -= 1;
	if (*nb_collectibles == 0)
		return (1);
	map[y][x] = '3';
	if (find_path_collectibles(x, y - 1, map, nb_collectibles) == 1 || \
		find_path_collectibles(x, y + 1, map, nb_collectibles) == 1)
		return (1);
	if (find_path_collectibles(x - 1, y, map, nb_collectibles) == 1 || \
		find_path_collectibles(x + 1, y, map, nb_collectibles) == 1)
		return (1);
	map[y][x] = '0';
	return (0);
}

int	pathfinder_collectibles(t_layout *layout)
{
	char	**path;
	int		is_path;
	int		nb_collec;
	
	nb_collec = layout->collectibles;
	path = path_clone(layout->map);
	is_path = (find_path_collectibles(layout->player_position->x, \
	layout->player_position->y, path, &layout->collectibles));
	ft_free_splitted_map(path);
	layout->collectibles = nb_collec;
	return (is_path);
}
