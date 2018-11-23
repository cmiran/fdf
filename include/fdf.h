/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:18 by cmiran            #+#    #+#             */
/*   Updated: 2018/10/25 18:40:30 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct	s_point
{
	int	z;
	int	color;
}				t_point;

typedef struct	s_env
{
	int		nx;
	int		ny;
	t_point	**map;
	void	*mlx;
	void	*win;
	int		scale;
	int		xmove;
	int		ymove;
	double	z;
	double	x;
	double	y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
}				t_env;

int				kill(char *str);
void			freekill(char *line, char *str);
void			clear_map(t_point **map, int ny);
t_point			**get_map(char *argv, t_env *env);
t_point			**pull_map(char *argv, int nb_x, int nb_y);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
void			draw_lines(t_env *e);

#endif
