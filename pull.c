/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:05:36 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/20 02:30:51 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_point	*pull_points(char *line, int nb_x, int *i)
{
	t_point *point;
	char	**str;
	int		j;

	str = NULL;
	if (!(point = (t_point *)malloc(sizeof(t_point) * nb_x)) || !(str = ft_strsplit(line, ' ')))
	return (0);
	j = -1;
	while (str[++j])
	{
		point[j].x = *i;
		point[j].y = j;
		if (ft_strchr(str[j], ','))
		{
			point[j].z = ft_atoi(ft_strcdup(str[j], ','));
			point[j].color = ft_atoi_base(ft_dupcstr(str[j], 'x'), 16);
		}
		else
		{
			point[j].z = ft_atoi(ft_strdup(str[j]));
			point[j].color = 0;
		}
	}
	ft_freetab(&str);
	return (point);
}

t_point	**pull_map(char *argv, int nb_x, int nb_y)
{
	t_point	**map;
	int		fd;
	int		i;
	char	*line;

	if (!(map = (t_point **)malloc(sizeof(t_point *) * nb_y)))
		kill("Error : a memory allocation has failed");
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (!(map[i] = pull_points(line, nb_x, &i)))
		{
			close(fd);
			freekill(line, "Error : a memory allocation has failed");
		}
		free(line);
		i++;
	}
	close(fd);
	return (map);
}
