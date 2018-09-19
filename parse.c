/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:57:46 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/19 19:51:56 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		line_len(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			len++;
			while (ft_isgraph(line[i]) && line[i])
				i++;
		}
		if (line[i] == '\0')
			break ;
		i++;
	}
	return (len);
}

void	check_line(char *line)
{
	int	i;
	int	j;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ',')
		{
			if (line[i + 1] != '0' && line[i + 2] != 'x')
				kill("Error : a color is not well formated");
			else
				i += 3;
			j = 1;
			while (line[i] != ' ' && line[i])
			{
				if (!ft_isxdigit(line[i]) || j > 6 || (line[i + 1] == ' ' && j % 2 != 0))
					kill("Error : a color is not well formated");
				i++;
				j++;
			}
		}
		if (line[i] == '\0')
			break ;
		if ((line[i] == '-' || line[i] == '+') && !ft_isdigit(line[i + 1]))
			kill("Error : a point is not well formated");
		if (line[i] != '-' && line[i] != '+' && line[i] != ' ' && !ft_isdigit(line[i]))
			kill("Error : map contains a forbidden character");
	}
}

void	check_map(char *argv, t_env *env)
{
	int		fd;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) == -1)
		kill("Error : corrupted map");
	while (get_next_line(fd, &line) != 0)
	{
		check_line(line);
		if (!env->nb_x)
			env->nb_x = line_len(line);
		else if (env->nb_x != line_len(line))
		{
			free(line);
			kill("Error : map is not a square or a rectangle");
		}
		env->nb_y += 1;
	}
	close(fd);
	free(line);
}

t_point	**get_map(char *argv, t_env *env)
{
	t_point	**map;

	check_map(argv, env);
	map = pull_map(argv, env->nb_x, env->nb_y);
	return (map);
}
