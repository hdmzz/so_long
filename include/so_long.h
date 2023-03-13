/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/13 05:11:35 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <X11/Xlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <X11/extensions/XShm.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_R 114
# define KEY_Q 113

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
	void		*pacman;
	void		*wall;
	int			moves_nbr;
	char		**map;
	int			width;
	int			height;
	int			nxt_dir;
}				t_game;

void	error_handler(char *msg);
void	ft_free_splitted_map(char **tab);

char	**check_map(char *file, t_layout *map_lay);

#endif
