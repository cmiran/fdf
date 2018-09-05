/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:05:36 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/05 17:27:05 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freekill(char *line, char *str)
{
	free(line);
	kill(str);
}

t_point	*pull_points(char *line, int nb_x)
{
	t_point *point;
	char		**str;
	int			i;
	int			j;

	if (!(point = (t_point *)malloc(sizeof(t_point) * nb_x)))
		freekill(line, "Error : a memory allocation has failed");
	if (!(str = ft_strsplit(line, ' ')))
		freekill(line, "Error : a memory allocation has failed");
	i = -1;
	j = -1;
	while (str[++i])
	{
		while (str[++j])
		{
			point->x = j;
			point->y = i;
			point->z = ft_atoi(ft_strcdup(str, ',');
		}
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
