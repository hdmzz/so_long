/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:26:34 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/05 12:21:26 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**path_clone(char **map)
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

static int	find_path(char **path, int y, int x)
{
	if (path[y][x] == '1' || path[y][x] == '3')
		return (0);
	if (path[y][x] == 'E')
		return (1);
	path[y][x] = '3';
	if (find_path(path, y - 1, x) == 1 || find_path(path, y + 1, x) == 1)
		return (1);
	if (find_path(path, y, x - 1) == 1 || find_path(path, y, x + 1) == 1)
		return (1);
	path[y][x] = '0';
	return (0);
}

int	pathfinder(t_layout *layout)
{
	char	**path;
	int		is_path;

	path = path_clone(layout->map);
	is_path = find_path(path, layout->player_position->y, \
		layout->player_position->x);
	ft_free_splitted_map(path);
	return (is_path);
}
