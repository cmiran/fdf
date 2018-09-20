/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:57:46 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/20 11:27:19 by cmiran           ###   ########.fr       */
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
int	check_line2(char *line, int *i)
{
	int	j;

	if (line[*i + 1] != '0' && line[*i + 2] != 'x')
		return (0);
//		freekill(line, "Error : a color is not well formated");
	else
		*i += 3;
	j = 1;
	while (line[*i] != ' ' && line[*i])
	{
		if (!ft_isxdigit(line[*i]) || j > 6 || (line[*i + 1] == ' ' && j % 2 != 0))
			return (0);
//			freekill(line, "Error : a color is not well formated");
		*i += 1;
		j++;
	}
	return (1);
}
	
int	check_line1(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ',')
			if (!check_line2(line, &i))
				return (0);
		if (line[i] == '\0')
			break ;
		if ((line[i] == '-' || line[i] == '+') && !ft_isdigit(line[i + 1]))
			return (0);
//			freekill(line, "Error : a point is not well formated");
		if (line[i] != '-' && line[i] != '+' && line[i] != ' ' && !ft_isdigit(line[i]))
			return (0);
//			freekill(line, "Error : map contains a forbidden character");
	}
	return (1);
}

void	check_map(char *argv, t_env *env)
{
	int		fd;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) == -1)
		kill("Error : corrupted map");
	while (get_next_line(fd, &line) != 0)
	{
		if (!check_line1(line))
		{
			close(fd);
			freekill(line, "Error : map is not well formated");
		}

		if (!env->nb_x)
			env->nb_x = line_len(line);
		else if (env->nb_x != line_len(line))
		{
			close(fd);
			freekill(line, "Error : map is not a square or a rectangle");
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
