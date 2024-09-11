#include "../includes/ft_so_long.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_exit(char **map, char **temp, char *str)
{
	if (temp)
		ft_freemap(temp);
	if (map)
		ft_freemap(map);
	ft_error(str);
	exit(1);
}

char	**allocate_temp(int rows, int cols, char **map)
{
	char	**temp;
	int		i;

	temp = malloc((rows + 1) * sizeof(char *));
	if (!temp)
		ft_exit(map, 0, "Error\nCan't allocate memory.\n");
	i = 0;
	while (i < rows)
	{
		temp[i] = malloc((cols + 1) * sizeof(char));
		if (!temp[i])
			ft_exit(map, temp, "Error\nCan't allocate memory.\n");
		i++;
	}
	i = 0;
	while (i < rows)
	{
		ft_strcpy(temp[i], map[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		rows;
	char	**temp;

	if (argc != 2)
	{
		ft_error("Error\nInvalid number of arguments\n");
		exit(1);
	}
	if (!is_ber_file(argv[1]))
	{
		ft_error("Error\nThe file must have a .ber extension.\n");
		exit(1);
	}
	map = get_map(argv[1], &rows);
	check_map(map, rows);
	check_walls(map, rows);
	temp = allocate_temp(rows, ft_strlen(map[0]), map);
	if (!check_path(temp, rows))
		ft_exit(map, temp, "Error\nNo valid path.\n");
	ft_freemap(temp);
	ft_start_window(map, rows);
}
