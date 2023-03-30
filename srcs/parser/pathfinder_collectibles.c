/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_collectibles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:36 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/29 19:39:36 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

static int	find_path_collectibles(int x, int y, t_layout *layout)
{
	if (layout->map_dup[y][x] == '1' || layout->map_dup[y][x] == '3')
		return (0);
	if (layout->map_dup[y][x] == 'C')
		layout->collectibles -= 1;
	if (layout->collectibles == 0)
		return (1);
	layout->map_dup[y][x] = '3';
	layout->nb_moves += 1;
	if (layout->nb_moves > layout->nb_moves_max)
		return (0);
	if (find_path_collectibles(x, y - 1, layout) == 1 || \
		find_path_collectibles(x, y + 1, layout) == 1)
		return (1);
	if (find_path_collectibles(x - 1, y, layout) == 1 || \
		find_path_collectibles(x + 1, y, layout) == 1)
		return (1);
	layout->map_dup[y][x] = '0';
	return (0);
}

int	pathfinder_collectibles(t_layout *layout)
{
	char	**path;
	int		is_path;
	int		nb_collec;
	
	nb_collec = layout->collectibles;
	layout->map_dup = path_clone(layout->map);
	layout->nb_moves_max = (layout->rows * layout->columns) * 2;
	layout->nb_moves = 0;
	is_path = (find_path_collectibles(layout->player_position->x, \
		layout->player_position->y, layout));
	ft_free_splitted_map(layout->map_dup);
	layout->collectibles = nb_collec;
	return (is_path);
}
