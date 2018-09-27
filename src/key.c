/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:52:58 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/27 13:12:17 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 0, 0x31ff1f, "quit  -> esc");
	mlx_string_put(e->mlx, e->win, 5, 17, 0x31ff1f, "move  -> ^ v < >");
	mlx_string_put(e->mlx, e->win, 5, 34, 0x31ff1f, "zoom  -> j k");
	mlx_string_put(e->mlx, e->win, 5, 51, 0x31ff1f, "depth -> w s");
	draw_lines(e);
	return (0);	
}

int	key3(int keycode, t_env *e)
{
	if (keycode == 13)
	{
		if (e->z <= 30.)
			e->z += 0.1;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 1)
	{
		if (e->z >= -30.)
			e->z -= 0.1;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	return (0);
}

int	key2(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->ymove -= 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 40)
	{
		if (e->scale <= 95)
			e->scale += 1;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 38)
	{
		if (e->scale >= -35)
			e->scale -= 1;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	key3(keycode, e);
	return (0);	
	
}

int	key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		e->xmove -= 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 124)
	{
		e->xmove += 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 125)
	{
		e->ymove += 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	key2(keycode, e);
	return (0);
}