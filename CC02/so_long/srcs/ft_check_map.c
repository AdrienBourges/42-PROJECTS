#include "../includes/ft_so_long.h"

int	is_ber_file(char *str)
{	
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return (str[len - 4] == '.' &&
			str[len - 3] == 'b' &&
			str[len - 2] == 'e' &&
			str[len - 1] == 'r');
}

void ft_exit2(int *line_lengths, char *str)
{
	if (line_lengths)
		free(line_lengths);	
	ft_error(str);
	exit(1);
}

void	map_info(char *filename, int **line_lengths, int *line_count)
{
	int		fd;
	int		length;
	int		count;
	char	buffer;
	int		current_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit2(0, "Error\n File is incorrect\n");
	length = 0;
	count = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			count++;
	}
	close(fd);
	*line_count = count;
	*line_lengths = malloc(sizeof(int) * count);
	if (!*line_lengths)
		ft_exit2(0, "Error\n Can't allocate  memory.\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit2(*line_lengths, "Error\n Can't open file.\n");
	current_line = 0;
	while (read(fd, &buffer, 1) > 0) 
	{
		if (buffer == '\n') 
		{
			(*line_lengths)[current_line++] = length;
			length = 0;
		} 
		else 
			length++;
	}
	close(fd);
}

char **get_map(char *filename, int *rows)
{
	int *line_lengths;

	line_lengths = NULL;
	map_info(filename, &line_lengths, rows);

	char **map = malloc(sizeof(char *) * (*rows + 1));
	if (!map)
	{
		free(line_lengths);
		ft_error("Error\n Can't allocate memory.\n");
		exit(1);
	}
	for (int i = 0; i < *rows; i++) 
	{
		map[i] = malloc(line_lengths[i] + 1);
		if (!map[i])
		{
			ft_freemap(map);
			free(line_lengths);
			ft_error("Error\n Can't allocate memory.\n");
			exit(1);
		}
	}
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_freemap(map);
		free(line_lengths);
		ft_error("Error\n Can't open file.\n");
		exit(1);
	}
	int i;
	for (i = 0; i < *rows; i++) 
	{
		read(fd, map[i], line_lengths[i]);
		map[i][line_lengths[i]] = '\0';
		read(fd, &(char){0}, 1);  // Skip newline character
	}
	map[i] = NULL;
	close(fd);
	free(line_lengths);
	return map;
}

void ft_initstruct(t_map *info)
{
	info -> rows = 0;
	info -> cols = 0;
	info -> exits = 0;
	info -> collectibles = 0;
	info -> start_pos = 0;
}


void check_map(char **map, int rows)
{
	t_map info;
	int i;
	int j;
	int first_row_length;

	i = 0;
	j = 0;
	first_row_length = ft_strlen(map[0]);
	if (first_row_length == 0)
	{
		ft_error("Error\nThe map is invalid.\n");
		ft_freemap(map);
		exit(1);
	}	
	ft_initstruct(&info);
	while (i < rows) 
	{
		if ((int)ft_strlen(map[i]) != first_row_length)
		{
			ft_error("Error\nThe map is not rectangular.\n");
			ft_freemap(map);
			exit(1);
		}
		while (map[i][j] != '\0') 
		{
			if (map[i][j] == 'E') 
			{
				info.exits++;
			} 
			else if (map[i][j] == 'C') 
			{
				info.collectibles++;
			} 
			else if (map[i][j] == 'P') 
			{
				info.start_pos++;
			}
			else if (map[i][j] != '0' && map[i][j] != '1')
			{
				ft_error("Error\nThe map contains an invalid character.\n");
				ft_freemap(map);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (info.exits == 1 && info.collectibles >= 1 && info.start_pos == 1) 
	{
		return ;
	} 
	else 
	{
		ft_error("Error\nInvalid number of start/exit position and/or collectibles\n");
		ft_freemap(map);
	  	exit(1);
	}
}

void check_walls(char **map, int rows)
{
	int i;
	int len;

	len = ft_strlen(map[0]);
	i = 0;
	while (i < len) 
	{
        if (map[0][i] != '1') 
		{
			ft_error("Error\nThe map is not surrounded by walls.\n");
			ft_freemap(map);
			exit(1);
        }
        i++;
    }
	i = 0;
	while (i < len) {
        if (map[rows - 1][i] != '1') 
		{
			ft_error("Error\nThe map is not surrounded by walls.\n");
			ft_freemap(map);
			exit(1);
        }
        i++;
    }
	i = 0;
	while (i < rows)
	{
        if (map[i][0] != '1' || map[i][len - 1] != '1') 
		{
			ft_error("Error\nThe map is not surrounded by walls.\n");
			ft_freemap(map);
			exit(1);
        }
        i++;
    }
}

int flood_fill(char **map, int x, int y, t_map map_info)
{
	int	found_exit;
	if (x < 0 || y < 0 || x >= map_info.rows || y >= map_info.cols || map[x][y] == '1' || map[x][y] == 'F') 
	{
        return 0;
    }
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

int check_path(char **map, int rows)
{
	int player_x;
	int player_y;
	t_map size;

	size.rows = rows;
	size.cols = ft_strlen(map[0]);
	player_x = 0;
	player_y = 0;
	while (map[player_x][player_y])
	{
		while (map[player_x][player_y])
		{
			if (map[player_x][player_y] == 'P')
			{
				break;
			}
			player_y++;
		}
		if (map[player_x][player_y] == 'P')
			{
				break;
			}
		player_x++;
		player_y = 0;
	}
	int exit_reachable = flood_fill(map, player_x, player_y, size);
	int i;
   	int j;
		
	i = 0;
    while (i < rows) 
	{
        j = 0;
        while (j < size.cols) 
		{
            if (map[i][j] == 'C') 
			{
                return 0;  // Not all collectibles and the exit were reached
            }
            j++;
        }
        i++;
    }
	return exit_reachable;
}
