/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:15:01 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/23 17:29:46 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	is_ber_file(char *map)
{
	char	*extensions_check;

	extensions_check = ft_strnstr(map, ".ber", ft_strlen(map));
	if (!extensions_check || ft_strlen(extensions_check) != 4)
	{
		free(extensions_check);
		perror("Error\nExtensions check\n");
		exit(EXIT_FAILURE);
	}
}

static void	check_walls(char **rows, t_layout *map_lay)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(rows[0]);
	while (rows[i])
		i++;
	if (ft_strspn(rows[0], "1") != len || ft_strspn(rows[i - 1], "1") != len)
	{
		error_handler("Error\nError Walls\n");
		ft_free_splitted_map(rows);
	}
	i = 0;
	while (rows[i])
	{
		if (ft_strlen(rows[i]) != len)
			error_handler("Error\nMap is not rectangular\n");
		if ((rows[i][0] != '1') || (rows[i][len - 1] != '1'))
			error_handler("Error\nThe map isn't closed by walls\n");
		i++;
	}
	map_lay->rows = i;
	map_lay->columns = len;
}

static char	**splitter(t_layout *map_lay, int fd)
{
	char	**map;
	char	*line;
	char	*res;
	char	*temp;
	int		i;

	line = get_next_line(fd);
	res = ft_strdup("");
	i = 0;
	while (line)
	{
		temp = res;
		res = ft_strjoin(res, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	while (res[i++])
	{
		if (res[i] == 'C')
			map_lay->collectibles += 1;
		if (res[i] == 'E')
			map_lay->exit += 1;
		if (res[i] == 'P')
			map_lay->player += 1;
	}
	map = ft_split(res, '\n');
	free(res);
	free(line);
	return (map);
}

static void	ft_init_layout(t_layout *map_lay)
{
	map_lay->collectibles = 0;
	map_lay->exit = 0;
	map_lay->enter = 0;
	map_lay->player = 0;
	map_lay->rows = 0;
	map_lay->columns = 0;
}

void	check_map(char *file, t_layout *map_lay)
{
	char	**map;
	int		fd;

	is_ber_file(file);
	fd = open(file, O_RDONLY);
	ft_init_layout(map_lay);
	map = splitter(map_lay, fd);
	if (!map)
		exit(EXIT_FAILURE);
	if (map_lay->player != 1 || map_lay->exit != 1 || map_lay->collectibles < 1)
	{
		ft_free_splitted_map(map);
		error_handler("Error\nEnter or exit not ok\n");
	}
	check_walls(map, map_lay);
	close(fd);
	map_lay->map = map;
}
