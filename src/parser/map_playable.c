/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:10:35 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/08 21:21:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**path_clone(char **map)
{
	int		rows;
	char	**clone;
	int		i;

	rows = 0;
	i = -1;
	while (map[rows])
		rows++;
	clone = ft_calloc(rows + 1, sizeof(char *));
	if (!clone)
		return (NULL);
	while (map[++i])
		clone[i] = ft_strdup(map[i]);
	return (clone);
}

static void	flood(int x, int y, t_layout *layout)
{
	if (layout->map_dup[y][x] == '1' || layout->map_dup[y][x] == '3')
		return ;
	layout->map_dup[y][x] = '3';
	flood(x, y + 1, layout);
	flood(x, y - 1, layout);
	flood(x - 1, y, layout);
	flood(x + 1, y, layout);
	return ;
}

static int	check_collec_exit(t_layout *layout)
{
	int	i;

	i = 0;
	while (layout->map_dup[i])
	{
		if (ft_strchr(layout->map_dup[i], 'C') || \
			ft_strchr(layout->map_dup[i], 'E'))
			return (0);
		i++;
	}
	return (1);
}

int	pathfinder(t_layout *layout)
{
	int	is_path;
	int	nb_collec;

	nb_collec = layout->collectibles;
	layout->map_dup = path_clone(layout->map);
	layout->nb_moves_max = (layout->rows * layout->columns) * 2;
	layout->nb_moves = 0;
	flood(layout->player_position->x, layout->player_position->y, layout);
	is_path = check_collec_exit(layout);
	ft_free_splitted_map(layout->map_dup);
	layout->collectibles = nb_collec;
	return (is_path);
}
