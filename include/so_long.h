/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/07 20:20:42 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <errno.h>
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

void	error_handler(char *msg);
void	ft_free_splitted_map(char **tab);

#endif
