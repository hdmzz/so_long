/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/20 12:26:33 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdio.h>
# include <mlx.h>

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
# define SIZE 50


typedef struct s_layout
{
	int	collectibles;
	int	exit;
	int	enter;
	int	enemies;
	int	rows;
	int	columns;
}				t_layout;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_player
{
	void	*img;
	t_position	*curr_position;
	int		x;
	int		y;
}				t_player;

typedef struct s_game
{
	void		*id;
	void		*w_id;
	t_layout	*backgrnd;
	t_player	*pacman;
	void		*water;
	void		*wall;
	void		*collect;
	int			moves_nbr;
	char		**map;
	int			width;
	int			height;
	int			nb_collectibles;
	int			collected; 
}				t_game;

void	ft_init_map(t_game *game, int pac_pos);
void	ft_put_pac(t_game *game);
void	ft_put_map(t_game *game);
int	ft_update(t_game *game);

void	error_handler(char *msg);
void	ft_free_splitted_map(char **tab);

char	**check_map(char *file, t_layout *map_lay);
void	new_position(int x, int y, t_game *game, t_position *position);

void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);

int	legal_move(t_game *game, int x, int y);
int	pathfinder(t_game *game, int y, int x);

#endif
