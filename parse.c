/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:57:46 by cmiran            #+#    #+#             */
/*   Updated: 2018/05/10 17:29:39 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_line(char *line)
{
	static size_t	len;
	int						i;

	if (!len)
		len = ft_strlen(line);
	else if (len != ft_strlen(line))
		kill("Error : map is not a square or a rectangle");
	i = 0;
	while (line[i])
	{
		if (!(ft_isdigit(line[i])) && line[i] != ' ')
			kill("Error : map contains unsupported characters");
		i++;
	}
	return (0);
}

int pull_map(const int fd)
{
	char	*line;	

	while (get_next_line(fd, &line) != 0)
	{
		if (check_line(line) != 0)
			return (1);
		else

	}
}
