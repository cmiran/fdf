/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:18 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/29 05:53:29 by cmiran           ###   ########.fr       */
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
	t_point	**map;
	void	*mlx;
	void	*win;
	int	scale;
	int	xmove;
	int	ymove;
	double	z;
	double	x;
	double	y;
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}		t_env;

int		kill(char *str);
void		freekill(char *line, char *str);
t_point		**get_map(char *argv, t_env *env);
t_point		**pull_map(char *argv, int nb_x, int nb_y);
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
void		draw_lines(t_env *e);

#endif
