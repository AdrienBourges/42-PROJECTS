#include "../includes/ft_so_long.h"

void	allocate_map_memory(char **map, int *line_lengths, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		map[i] = malloc(line_lengths[i] + 1);
		if (!map[i])
		{
			ft_freemap(map);
			free(line_lengths);
			ft_error("Error\nCan't allocate memory.\n");
			exit(1);
		}
		i++;
	}
}

void	read_map_from_file(int fd, char **map, int *line_lengths, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		read(fd, map[i], line_lengths[i]);
		map[i][line_lengths[i]] = '\0';
		read(fd, &(char){0}, 1);
		i++;
	}
	map[i] = NULL;
}

char	**get_map(char *filename, int *rows)
{
	int		*line_lengths;
	int		fd;
	char	**map;

	line_lengths = NULL;
	map_info(filename, &line_lengths, rows);
	map = malloc(sizeof(char *) * (*rows + 1));
	if (!map)
	{
		free(line_lengths);
		ft_error("Error\nCan't allocate memory.\n");
		exit(1);
	}
	allocate_map_memory(map, line_lengths, *rows);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_freemap(map);
		ft_exit2(line_lengths, "Error\nCan't open file.\n");
	}
	read_map_from_file(fd, map, line_lengths, *rows);
	close(fd);
	free(line_lengths);
	return (map);
}

void	ft_initstruct(t_map *info)
{
	info -> rows = 0;
	info -> cols = 0;
	info -> exits = 0;
	info -> collectibles = 0;
	info -> start_pos = 0;
}

void	check_invalid_chars(char **map, t_map *info, int i, int j)
{
	if (map[i][j] == 'E')
		info->exits++;
	else if (map[i][j] == 'C')
		info->collectibles++;
	else if (map[i][j] == 'P')
		info->start_pos++;
	else if (map[i][j] != '0' && map[i][j] != '1')
	{
		ft_error("Error\nThe map contains an invalid character.\n");
		ft_freemap(map);
		exit(1);
	}
}
