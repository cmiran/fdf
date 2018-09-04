/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:05:36 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/04 19:04:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*pull_points(*line, nb_x)
{
	t_point *point;
	int			i;

	if (!(point = (t_point *)malloc(sizeof(t_point) * nb_x)))
	{
		free(&line);
		kill("Error : a memory allocation has failed");
	}
	i = 0;
	while (line[i])
	{
		
	
}

t_point	**pull_map(char *argv, int nb_x, int nb_y)
{
	t_point	**map;
	int 		fd;
	int			i;	
	char 		*line;

	if (!(map = (t_point **)malloc(sizeof(t_point *) * nb_y)))
		kill("Error : a memory allocation has failed");
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) != 0)
		map[i++] = pull_points(&line, nb_x);
	free(line);
	close(fd);
	return (map);
}
