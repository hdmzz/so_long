/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:35:43 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/07 21:23:39 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	error_handler(char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	ft_free_splitted_map(char **tab)
{
	char	**temp;

	temp = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(temp);
}
