/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:15:01 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/07 20:18:52 by hdamitzi         ###   ########.fr       */
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
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	free(extensions_check);
}

static void	check_walls(char **rows)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(rows[0]);
	while (rows[i])
		i++;
	if (ft_strspn(rows[0], "1") != len || ft_strspn(rows[i - 1], "1") != len)
	{
		error_handler("Error\nError Walls\n");
		ft_free_splitted_map(rows);
	}
	while (*rows)
	{
		if (ft_strlen(*rows) != len)
			error_handler("Error\nMap is nor rectangular\n");
		if (*rows[0] != 1 || *rows[len - 1] != 1)
			error_handler("Error\nThe map isn't closed by walls\n");
		rows++;
	}
}

static char	**splitter(char *file, t_layout *map_lay, int fd)
{
	char	**map;
	char	*line;
	char	*res;
	int		i;

	line = get_next_line(fd);
	res = ft_strdup("");
	i = 0;
	while (line)
	{
		res = ft_strjoin(res, line);
		line = get_next_line(fd);
	}
	while (res[i++])
	{
		if (res[i] == 'C')
			map_lay->collectibles += 1;
		if (res[i] == 'E')
			map_lay->exit += 1;
		if (res[i] == 'P')
			map_lay->exit += 1;
	}
	map = ft_split(res, '\n');
	return (map);
}

int	check_map(char *file)
{
	char		**map;
	int			i;
	t_layout	*map_lay;
	int			fd;

	is_ber_file(file);
	fd = open(file, O_RDONLY);
	map_lay = malloc(sizeof(t_layout));
	if (!map)
		exit(EXIT_FAILURE);
	map = splitter(file, map_lay, fd);
	if (map_lay->enter != 1 || map_lay->exit != 1)
	{
		ft_free_splitted_map(map);
		free(map_lay);
		error_handler("Error\nEnter or exit not ok\n");
	}
}
