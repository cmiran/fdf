/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/05/10 17:27:55 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	init(t_point 

int	param_check(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
		kill("Usage : ./fdf <filename>");
	if ((fd = open(argv[1], O_RDONLY)) == -1)	
		kill("Error : corrupted map");
	if (pull_map(fd) != 0)
		return (1);
}

int	main(int argc, char **argv)
{
	
}
