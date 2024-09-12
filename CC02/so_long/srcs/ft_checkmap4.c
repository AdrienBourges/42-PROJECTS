#include "../includes/ft_so_long.h"

void	check_row_length(char **map, int i, int first_row_length)
{
	if ((int)ft_strlen(map[i]) != first_row_length)
	{
		ft_error("Error\nThe map is not rectangular.\n");
		ft_freemap(map);
		exit(1);
	}
}

void	validate_map_content(char **map, int rows, t_map *info, int frl)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		check_row_length(map, i, frl);
		j = 0;
		while (map[i][j] != '\0')
		{
			check_invalid_chars(map, info, i, j);
			j++;
		}
		i++;
	}
}

void	check_map(char **map, int rows)
{
	t_map	info;
	int		first_row_length;

	first_row_length = ft_strlen(map[0]);
	if (first_row_length == 0)
	{
		ft_error("Error\nThe map is invalid.\n");
		ft_freemap(map);
		exit(1);
	}
	ft_initstruct(&info);
	validate_map_content(map, rows, &info, first_row_length);
	if (!(info.exits == 1 && info.collectibles >= 1 && info.start_pos == 1))
	{
		ft_error("Error\nWrong number of start/exit position and/or collecs\n");
		ft_freemap(map);
		exit(1);
	}
}

void	ft_exit_wall(char **map)
{
	ft_error("Error\nThe map is not surrounded by walls.\n");
	ft_freemap(map);
	exit(1);
}

void	check_walls(char **map, int rows)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1')
			ft_exit_wall(map);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (map[rows - 1][i] != '1')
			ft_exit_wall(map);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			ft_exit_wall(map);
		i++;
	}
}
