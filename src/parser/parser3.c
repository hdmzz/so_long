/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:03 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/09 01:44:38 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_walls2(t_layout *layout)
{
	int	i;
	char	**map;

	i = 0;
	map = layout->map;
	while (map[i])
	{
		if (ft_strspn(map[i], "01ECP") != ft_strlen(map[i]))
			error_parsing(layout, "Error\nmap\n");
		i++;
	}
}
