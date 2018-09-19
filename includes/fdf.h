/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:18 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/19 19:55:25 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_env
{
	int		nb_x;
	int		nb_y;
	t_point	**map;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_env;

int				kill(char *str);
void			freekill(char *line, char *str);
t_point			**get_map(char *argv, t_env *env);
t_point			**pull_map(char *argv, int nb_x, int nb_y);

#endif
