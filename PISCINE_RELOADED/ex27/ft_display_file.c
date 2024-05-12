#include "unistd.h"
#include "fcntl.h"

void ft_display(int fd)
{
	char buffer[1024];
	int bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 1024);
		write(1, buffer, bytes_read);
	}
	close (fd);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write (2, "Cannot read file.\n", 17);
			return (0);
		}
		ft_display(fd);
	}
	return (0);
}

