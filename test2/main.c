#include "../libft/libft.h"

int	main()
{
	char *str;
	char **tab;
	int 	i;
	int		j;

	str = "lol lala caca pipi lol,de   de";
	tab = ft_strsplit(str, ' ');
	while (tab[i])
	{
		while (tab[j])
		{
			printf("%s\n", tab[j]);
			j++;
		}
		i++;
	}
	return (0);
}
