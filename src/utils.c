/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:27:04 by cmiran            #+#    #+#             */
/*   Updated: 2018/10/22 21:00:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	del_point(t_point *p)
{
	free(p);
	p = NULL;
}*/

void	clear_fdf(t_env *e)
{
	int	x;
	int	y;
	
	if (e->map)
	{
		y = 0;
		while (y < e->ny)
		{
			x = 0;
			printf("nx = %i\n", e->nx);
			while (x < e-> nx)
			{
				free(e->map[y][x]);
				printf("x = %i\n", x);	
				x++;
			}
			free(e->map[y]);
			y++;
		}
		printf("ny = %i\n", e->ny);
		printf("y = %i\n", y);
		free(e->map);
	}
	if (e)
		free(e);
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
