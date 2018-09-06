/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/06 19:34:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_point	**map;
	int	i;
	int	j;

	map = NULL;
	if (argc == 2)
		map = get_map(argv[1]);
	else	
		kill("Usage : ./fdf <filename>");
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[j])
		{
			printf("-\n");
			printf("x = %d\n", map[i][j].x);
			printf("y = %d\n", map[i][j].x);
			printf("z = %d\n", map[i][j].x);
			printf("color = %d\n", map[i][j].color);
			printf("-\n");
			j++;
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}
