/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:27:04 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/20 02:05:13 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	freekill(char *line, char *str)
{
	free(line);
	kill(str);
}
