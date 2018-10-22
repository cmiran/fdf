/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:49:57 by cmiran            #+#    #+#             */
/*   Updated: 2018/10/22 16:52:12 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int color, t_env *e)
{
	double	tx;
	int		dx;
	int		dy;

	tx = 0;
	dx = e->x1 - e->x0;
	dy = e->y1 - e->y0;
	while (tx <= 1)
	{
		e->x = e->x0 + dx * tx;
		e->y = e->y0 + dy * tx;
		mlx_pixel_put(e->mlx, e->win, e->x + e->xmove,
				e->y + e->ymove, color);
		tx += 1 / sqrt(dx * dx + dy * dy);
	}
}

void	vertical(t_env *e, int j, int i)
{
	e->x0 = 20 + i * e->scale + j * e->scale;
	e->x1 = 20 + i * e->scale + (j + 1) * e->scale;
	e->y0 = (800 + j * e->scale) / 2
		- (i * e->scale + e->z * e->map[j][i].z) / 2;
	e->y1 = (800 + (j + 1) * e->scale) / 2
		- (i * e->scale + e->z * e->map[j + 1][i].z) / 2;
	draw_line(e->map[j][i].color, e);
}

void	horizontal(t_env *e, int j, int i)
{
	e->x0 = 20 + i * e->scale + j * e->scale;
	e->x1 = 20 + (i + 1) * e->scale + j * e->scale;
	e->y0 = (800 + j * e->scale) / 2
		- (i * e->scale + e->z * e->map[j][i].z) / 2;
	e->y1 = (800 + j * e->scale) / 2
		- ((i + 1) * e->scale + e->z * e->map[j][i + 1].z) / 2;
	draw_line(e->map[j][i].color, e);
}

void	draw_lines(t_env *e)
{
	int	i;
	int	j;

	j = 0;
	while (j < e->ny)
	{
		i = 0;
		while (i < e->nx - 1)
			horizontal(e, j, i++);
		j++;
	}
	j = 0;
	while (j < e->ny - 1)
	{
		i = 0;
		while (i < e->nx)
			vertical(e, j, i++);
		j++;
	}
}
