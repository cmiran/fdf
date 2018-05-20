/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/05/20 15:06:16 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		
	}
	else	
		kill("Usage : ./fdf <filename>");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		kill("Error : corrupted map");
	check_map(fd, &nb_x, &nb_y);

	exit(EXIT_SUCCESS);
}
