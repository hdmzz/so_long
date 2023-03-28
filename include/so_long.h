/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/27 14:36:24 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../mlx_linux/mlx.h"
//# include <mlx.h>

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

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_layout
{
	int			collectibles;
	int			exit;
	int			player;
	int			rows;
	int			columns;
	t_position	*player_position;
	char		**map;
}				t_layout;

typedef struct s_player
{
	void		*img;
	t_position	*curr_position;
	int			x;
	int			y;
}				t_player;

typedef struct s_game
{
	void		*id;
	void		*w_id;
	t_layout	*backgrnd;
	t_player	*pacman;
	void		*player;
	void		*water;
	void		*wall;
	void		*fish;
	void		*exit;
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
int		ft_update(t_game *game);

void	error_handler(char *msg);
void	error_parsing(t_layout *layout, char *msg);

void	ft_free_splitted_map(char **tab);

void	check_map(char *file, t_layout *map_lay);
void	check_walls(t_layout *map_lay);
int		is_rectangular(t_layout *layout);

void	new_position(int x, int y, t_game *game, t_position *position);
void	ft_layout(t_layout *layout);

void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);

int		legal_move(t_game *game, int x, int y);
int		pathfinder(t_layout *layout);

int		close_game(t_game *game);

#endif
