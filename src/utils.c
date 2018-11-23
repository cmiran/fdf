/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:27:04 by cmiran            #+#    #+#             */
/*   Updated: 2018/11/05 10:43:39 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_map(t_point **map, int ny)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < ny)
			free(map[i++]);
		free(map);
	}
}

int		kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	freekill(char *line, char *str)
{
	if (line)
		free(line);
	kill(str);
}
