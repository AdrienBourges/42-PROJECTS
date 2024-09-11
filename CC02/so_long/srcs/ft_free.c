#include "../includes/ft_so_long.h"

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(char *str)
{
	write (2, str, ft_strlen(str));
}
