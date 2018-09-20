/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:18 by cmiran            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/11 12:52:11 by cmiran           ###   ########.fr       */
=======
/*   Updated: 2018/09/19 21:28:28 by cmiran           ###   ########.fr       */
>>>>>>> 6185a0cff1a3c96c878bf5c2b9312774fb08652b
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

<<<<<<< HEAD
=======
# include <mlx.h>
>>>>>>> 6185a0cff1a3c96c878bf5c2b9312774fb08652b
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
