#include "../includes/ft_so_long.h"

int	is_ber_file(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return (str[len - 4] == '.' && str[len - 3] == 'b'
		&& str[len - 2] == 'e' && str[len - 1] == 'r');
}

void	ft_exit2(int *line_lengths, char *str)
{
	if (line_lengths)
		free(line_lengths);
	ft_error(str);
	exit(1);
}

int	open_and_count_lines(char *filename, int *line_count)
{
	int		fd;
	char	buffer;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit2(0, "Error\nFile is incorrect\n");
	count = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			count++;
	}
	close(fd);
	*line_count = count;
	return (fd);
}

void	allocate_lengths(int fd, int *line_lengths)
{
	char	buffer;
	int		length;
	int		current_line;

	length = 0;
	current_line = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			line_lengths[current_line++] = length;
			length = 0;
		}
		else
			length++;
	}
	close(fd);
}

void	map_info(char *filename, int **line_lengths, int *line_count)
{
	int	fd;

	fd = open_and_count_lines(filename, line_count);
	*line_lengths = malloc(sizeof(int) * (*line_count));
	if (!*line_lengths)
		ft_exit2(0, "Error\nCan't allocate memory.\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit2(*line_lengths, "Error\nCan't open file.\n");
	allocate_lengths(fd, *line_lengths);
}
