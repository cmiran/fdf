/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:05:36 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/10 14:35:52 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	freekill(char *line, char *str)
{
	free(line);
	kill(str);
}

t_point	*pull_points(char *line, int nb_x, int *i)
{
	t_point *point;
	char		**str;
	int			j;

	if (!(point = (t_point *)malloc(sizeof(t_point) * nb_x)))
		freekill(line, "Error : a memory allocation has failed");
	if (!(str = ft_strsplit(line, ' ')))
		freekill(line, "Error : a memory allocation has failed");
	j = -1;
	while (str[++j])
	{
		point->x = *i;
		point->y = j;
		if (ft_strchr(str[j], ','))
		{
			point->z = ft_atoi(ft_strcdup(str[j], ',')); 
			point->color = ft_atoi_base(ft_dupcstr(str[j], 'x'), 16);
		}
		else
		{
			point->z = ft_atoi(ft_strdup(str[j]));
			point->color = 0;
		}
	}
	return (point);
}

t_point	**pull_map(char *argv, int nb_x, int nb_y)
{
	t_point	**map;
	int 	fd;
	int	i;	
	char 	*line;

	if (!(map = (t_point **)malloc(sizeof(t_point *) * nb_y)))
		kill("Error : a memory allocation has failed");
	fd = open(argv, O_RDONLY);
	i = -1;
	while (get_next_line(fd, &line) != 0)
	{
		map[++i] = pull_points(line, nb_x, &i);
		free(line);
	}
	close(fd);
	return (map);
}
