#include "../includes/ft_so_long.h"

int	flood_fill(char **map, int x, int y, t_map map_info)
{
	int	found_exit;

	if (x < 0 || y < 0 || x >= map_info.rows
		|| y >= map_info.cols || map[x][y] == '1'
		|| map[x][y] == 'F')
		return (0);
	if (map[x][y] == 'E')
		return (1);
	map[x][y] = 'F';
	found_exit = 0;
	found_exit |= flood_fill(map, x + 1, y, map_info);
	found_exit |= flood_fill(map, x - 1, y, map_info);
	found_exit |= (flood_fill(map, x, y + 1, map_info));
	found_exit |= (flood_fill(map, x, y - 1, map_info));
	return (found_exit);
}

void	find_player_position(char **map, int *player_x, int *player_y)
{
	*player_x = 0;
	*player_y = 0;
	while (map[*player_x][*player_y])
	{
		while (map[*player_x][*player_y])
		{
			if (map[*player_x][*player_y] == 'P')
				return ;
			(*player_y)++;
		}
		(*player_x)++;
		*player_y = 0;
	}
}

int	check_collectibles(char **map, t_map size, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < size.cols)
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **map, int rows)
{
	int		player_x;
	int		player_y;
	t_map	size;

	size.rows = rows;
	size.cols = ft_strlen(map[0]);
	find_player_position(map, &player_x, &player_y);
	if (!flood_fill(map, player_x, player_y, size))
		return (0);
	if (!check_collectibles(map, size, rows))
		return (0);
	return (1);
}
