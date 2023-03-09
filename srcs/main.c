/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:17:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/09 10:36:29 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



void	init_game(t_layout *lay, t_game *game, char **map)
{
	game->moves_nbr = 0;
	
}

void	so_long(char *file)
{
	t_layout	map_lay;
	t_game		game;
	char		**map;
	void		*id;

	map = check_map(file, &map_lay);
	game.id = mlx_init();
	game.w_id = mlx_new_window(id, 32, 32 * 80, "so_long");
	game.backgrnd = &map_lay;
}

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	exit(EXIT_SUCCESS);
}
