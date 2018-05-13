/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:57:46 by cmiran            #+#    #+#             */
/*   Updated: 2018/05/13 18:08:26 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			break;
		i++;
	}
	return (len);
}

void	check_point(char *line)
{
	int	i;
	int j;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			if (line[i + 1] != '0' && line[i + 2] != 'x')
				kill("Error : a color is not well formated");
			else
				i += 3;
			j = 1;
			while (line[i] != ' ')
			{
				if (!ft_isxdigit(line[i]) && (j > 6 || j % 2 != 0))
					kill("Error : a color is not well formated");
				i++;
				j++;
			}
		}
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			kill("Error : map contains a forbidden character");
		i++;
	}
}

void	check_line(char *line, int *nb_x)
{
	printf("%s\n", line);
	if (!ft_isdigit(line[0]) || !ft_isxdigit(line[ft_strlen(line) - 1]))
		kill("Error : map is not well formated or contains a forbidden character");
	else
		check_point(line);
	if (!*nb_x)
		*nb_x = line_len(line);
	else if (*nb_x != line_len(line))
		kill("Error : map is not a square or a rectangle");
}

void 	check_map(const int fd, int *nb_x, int *nb_y)
{
	char				*line;

	*nb_y = 0;
	while (get_next_line(fd, &line) != 0)
	{
		check_line(line, nb_x);
		*nb_y += 1;
	}
}
