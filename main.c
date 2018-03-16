/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/03/16 11:31:51 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	params_check(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
		return (kill("Usage : ./fdf <filename>"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)	
		return (kill("Error : corrupted map"));
	if (pull_map(fd, *argv) > 0)
		return ();
}

int	main(int argc, char **argv)
{

}
