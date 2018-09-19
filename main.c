/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/19 19:14:49 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	init_env(t_env *env)
{
	env->nb_x = 0;
	env->nb_y = 0;
	env->map = NULL;
/*	if (!(env->mlx_id = mlx_init(void)))
		kill("Error : mlx failed to initialize");
	if (!(env->win_id = mlx_new_window(env->mlx_id, 1200, 720, argv[1])))
		kill("Error : mlx failed to create a new window");*/
	env->mlx_id = NULL;
	env->win_id = NULL;
}

int	main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	if (argc > 1)
		env.map = get_map(argv[1], &env);
	else	
		kill("Usage : ./fdf <filename>");
/*	int i = 0;
	while (i < env.nb_y)
	{
		int j = 0;
		while (j < env.nb_x)
		{
			printf("-\nx = %d\n", env.map[i][j].x);
			printf("y = %d\n", env.map[i][j].y);
			printf("z = %d\n", env.map[i][j].z);
			printf("color = %d\n-\n", env.map[i][j].color);
			j++;
		}
		i++;
	}
	printf("nb_x : %d\nnb_y : %d\n", env.nb_x, env.nb_y);*/
	exit(EXIT_SUCCESS);
}
