/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:26:34 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/19 10:09:05 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**path_clone(char **map)
{
	int		map_len;
	int		rows;
	char	**clone;
	int		i;

	map_len = ft_strlen(*map);
	rows = 0;
	i = 0;
	while (map[rows])
		rows++;
	clone = malloc(sizeof(char *) * rows + 1);
	if (!clone)
		return (NULL);
	while (map[i])
		clone[i++] = ft_strdup(map[i]);
	i = 0;
	while (clone[i])
		ft_memset(clone[i++], '0', map_len);
	return (clone);
}

static int	find_path(char **real_map, char **path, int y, int x)//il faut que x et y soit les coordo de P
{
	if (real_map[y][x] == '0' || real_map[y][x] == 'P' || real_map[y][x] == 'C')
	{
		path[y][x] = '1';
		if (find_path(real_map, path, y, x + 1) == 1)//right
			return (1);
		if (find_path(real_map, path, y + 1, x) == 1)//down
			return (1);
		if (find_path(real_map, path, y - 1, x) == 1)//up
			return (1);
		if (find_path(real_map, path, y, x - 1) == 1)//left
			return (1);
	}
	if (real_map[y][x] == 'E')
		return (2);
	return (0);
}

int	pathfinder(t_game *game, int y, int x)
{
	char	**path;
	int		is_path;

	ft_printf("%c\n", game->map[y][x]);//
	path = path_clone(game->map);
	is_path = find_path(game->map, path, y, x);
	while (*path)
	{
		ft_printf("%s\n", *path);
		path++;
	}
}