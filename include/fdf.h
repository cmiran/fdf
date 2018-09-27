/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:18 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/27 13:15:03 by cmiran           ###   ########.fr       */
/*   Updated: 2018/09/19 21:28:28 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct	s_point
{
	int	z;
	int	color;
}		t_point;

typedef struct	s_env
{
	int	nx;
	int	ny;
	int	xmove;
	int	ymove;
	int	scale;
	double	z;
	t_point	**map;
	double		x;
	double		y;
	double		x0;
	double		x1;
	double		y0;
	double	y1;
	void	*mlx;
	void	*win;
}		t_env;

int		kill(char *str);
void		freekill(char *line, char *str);
t_point		**get_map(char *argv, t_env *env);
t_point		**pull_map(char *argv, int nb_x, int nb_y);
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
void		draw_lines(t_env *e);

#endif
