/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:22:03 by cmiran            #+#    #+#             */
/*   Updated: 2018/05/10 13:46:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	main(int argc, char **argv)
{
	int 	fd;
	char	*line;
	
	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(line = ft_strnew(1)))
		return (0);
	while (get_next_line(fd, &line) != 0)
		printf("%s\n", line);
	return (0);
}
