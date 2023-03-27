/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:15:01 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/27 14:05:03 by hdamitzi         ###   ########.fr       */
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


static void	splitter(t_layout *map_lay, int fd)//split the file into slplit
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
	map = ft_split(res, '\n');
	free(res);
	free(line);
	map_lay->map = map;
	ft_layout(map_lay);
}

static void	ft_init_layout(t_layout *map_lay)
{
	map_lay->collectibles = 0;
	map_lay->exit = 0;
	map_lay->player = 0;
	map_lay->rows = 0;
	map_lay->columns = 0;
}

void	check_walls(t_layout *map_lay)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(map_lay->map[0]);
	while (map_lay->map[++i])
	{
		if (ft_strspn(map_lay->map[i], "10EPC") != len)
			error_parsing(map_lay, "Error map must be made of 01ECP");
		if ((map_lay->map[i][0] != '1' && map_lay->map[i][len - 1] != '1') \
			|| (map_lay->map[i][0] != '1' || map_lay->map[i][len - 1] != '1'))
			error_parsing(map_lay, "Error\nMap isn't close by walls");
	}
	if (ft_strspn(map_lay->map[0], "1") != len || ft_strspn(map_lay->map[i - 1], "1") != len)
	{
		error_handler("Error\nError Walls\n");
		ft_free_splitted_map(map_lay->map);
	}
	
}

void	check_map(char *file, t_layout *map_lay)
{
	int		fd;

	is_ber_file(file);
	fd = open(file, O_RDONLY);
	ft_init_layout(map_lay);//layout init a zero
	splitter(map_lay, fd);
	if (!map_lay->map)
		exit(EXIT_FAILURE);
	if (map_lay->player != 1 || map_lay->exit != 1 || map_lay->collectibles < 1)
	{
		ft_free_splitted_map(map_lay->map);
		error_handler("Error\nEnter or exit not ok\n");
	}
	close(fd);
}
