/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/09 10:37:53 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <stdio.h>
# include <mlx.h>

typedef struct s_layout
{
	int	collectibles;
	int	exit;
	int	enter;
	int	enemies;
	int	rows;
	int	columns;
}				t_layout;

typedef struct s_game
{
	void		*id;
	void		*w_id;
	t_layout	*backgrnd;
	int			moves_nbr;
	char		**map;
	int			width;
	int			height;
	int			nxt_move;
}				t_game;

void	error_handler(char *msg);
void	ft_free_splitted_map(char **tab);

char	**check_map(char *file, t_layout *map_lay);

#endif
