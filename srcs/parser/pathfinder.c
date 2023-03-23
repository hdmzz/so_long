/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:26:34 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/23 16:51:04 by hdamitzi         ###   ########.fr       */
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
	return (clone);
}

static void print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

static int	find_path(char **path, int y, int x)//il faut que x et y soit les coordo de P
{
	// sleep(2);
	print_map(path);
	ft_printf("\n");
	ft_printf("\n");
	if (path[y][x] == '1' || path[y][x] == '3')//1 - wall 3 - taken path
		return (0);
	if (path[y][x] == 'E')//si attein la sortie n'appelera pas de nvx la fonction
		return (1);
	path[y][x] = '3';//taken path;
	if (find_path(path, y - 1, x) == 1 || find_path(path, y + 1, x) == 1)
		return (1);
	if (find_path(path, y, x - 1) == 1 || find_path(path, y, x + 1) == 1)
		return (1);
	path[y][x] = '0';//si aucun des mouvement n'est possible on remet 0 et on retourn false
	//donc la fonction recursive revient sur sa trace
	return (0);
}

int	pathfinder(t_game *game, int y, int x)
{
	char	**path;
	int		is_path;

	ft_printf("%c\n", game->map[y][x]);//
	path = path_clone(game->map);//free
	is_path = find_path( path, y, x);
	ft_free_splitted_map(path);
	if (is_path)
		return (1);
	return (0);
}
