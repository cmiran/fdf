/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:05:36 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/27 12:56:04 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*pull_points(char *line, int nx)
{
	t_point *point;
	char	**str;
	int		i;

	str = NULL;
	if (!(point = (t_point *)malloc(sizeof(t_point) * nx)) || !(str = ft_strsplit(line, ' ')))
		return (0);
	i = -1;
	while (str[++i])
	{
		if (ft_strchr(str[i], ','))
		{
			point[i].z = ft_atoi(ft_strcdup(str[i], ','));
			point[i].color = ft_atoi_base(ft_dupcstr(str[i], 'x'), 16);
		}
		else
		{
			point[i].z = ft_atoi(ft_strdup(str[i]));
			point[i].color = 0xFFFFFF;
		}
	}
	ft_freetab(&str);
	return (point);
}

t_point	**pull_map(char *argv, int nx, int ny)
{
	t_point	**map;
	int		fd;
	int		i;
	char	*line;

	if (!(map = (t_point **)malloc(sizeof(t_point *) * ny)))
		kill("Error : a memory allocation has failed");
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (!(map[i] = pull_points(line, nx)))
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
