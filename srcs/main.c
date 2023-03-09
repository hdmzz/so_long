/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/09 08:19:27 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_layout *lay, t_game *game)
{
	game->moves = 0;
	
}

void	so_long(char *file)
{
	t_layout	*map_lay;
	char		**map;
	void		*id;
	void		*win_id;

	map_lay = malloc(sizeof(t_layout));
	map = check_map(file, map_lay);
	id = mlx_init();
	if (id)
		win_id = mlx_new_window(id, 32, 32, "so_long");
}

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	exit(EXIT_SUCCESS);
}
