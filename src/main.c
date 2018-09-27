/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/27 12:52:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_env *e, char *file)
{
	e->nx = 0;
	e->ny = 0;
	e->map = get_map(file, e);
	e->z = 5.0;
	e->xmove = 0;
	e->ymove = 0;
	if (e->ny >= e->nx)
		e->scale = 400 / e->ny;
	else
		e->scale = 400 / e->nx;
	if (!(e->mlx = mlx_init()))
		kill("Error : mlx failed> to initialize");
	if (!(e->win = mlx_new_window(e->mlx, 800, 800, file)))
		kill("Error : mlx failed to create a new window");
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_key_hook(e->win, &key_hook, e);
	mlx_loop(e->mlx);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc > 1)
	{
		init_env(&e, argv[1]);
	}
	else
		kill("Usage : ./fdf <filename>");
/*	int i = 0;
	while (i < e.nb_y)
	{
		int j = 0;
		while (j < e.nb_x)
		{
			printf("-\nx = %d\n", e.map[i][j].x);
			printf("y = %d\n", e.map[i][j].y);
			printf("z = %d\n", e.map[i][j].z);
			printf("color = %d\n-\n", e.map[i][j].color);
			j++;
		}
		i++;
	}
	printf("nb_x : %d\nnb_y : %d\n", e.nb_x, e.nb_y);*/
	exit(EXIT_SUCCESS);
}
