#include "get_next_line.h"

char	*ft_stock_text(int fd, char *line) // fonction qui va permettre de stocker dynamiquement le texte dans la limite du buffer_size disponible, si buffer_size > nb de carac on stock tout directement car line est vide au premier appel de fonction
{
	char	*temp;
	int		byte_index;

	temp = malloc (BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	byte_index = 1;
	while (byte_index > 0 && ft_is_newline(line) == 0)
	{
		byte_index = read(fd, temp, BUFFER_SIZE);
		if (byte_index == -1)
		{
			free(temp);
			free(line);
			return (NULL);
		}
		temp[byte_index] = '\0';
		line = ft_merge(line, temp);
	}
	free(temp);
	return (line);
}

char	*ft_append_line(char *line) // fonction qui sert a ajouter la ligne dans un string et le return
{
	char	*result;
	size_t	i;

	i = 0;
	if (!line || !*line)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	result = malloc (i + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		result[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
	}
	else
		result[i] = '\0';
	return (result);
}

char	*ft_free_and_return(char *result, char *str_temp, size_t i)
{
	size_t	j;

	j = 0;
	while (str_temp[i])
		result[j++] = str_temp[i++];
	result[j] = '\0';
	free(str_temp);
	return (result);
}

char	*ft_clear_line(char *str_temp) // fonction pour clean le static string jusquau premier \n rencontre  avant le prochain appel de gnl
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str_temp || !*str_temp)
	{
		free (str_temp);
		return (NULL);
	}
	i = 0;
	while (str_temp && str_temp[i] != '\n' && str_temp[i])
		i++;
	i++;
	j = 0;
	while (j + i < ft_strlen(str_temp))
		j++;
	if (j == 0)
	{
		free(str_temp);
		return (NULL);
	}
	result = malloc (j + i + 1);
	if (!result)
	{
		free(str_temp);
		return (NULL);
	}
	return (ft_free_and_return(result, str_temp, i));
}

void __attribute__((destructor))	free_buffers(void)
{
	get_next_line(-42);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*str_temp[1024];

	result = NULL;
	if (fd == -42)
	{
		fd = 0;
		while (fd <= 1023)
		{
			if (str_temp[fd])
				free(str_temp[fd]);
			fd++;
		}
		return (NULL);
	}
	if ((fd < 0 || BUFFER_SIZE <= 0))
		return (NULL);
	str_temp[fd] = ft_stock_text(fd, str_temp[fd]);
	if (str_temp[fd] && *str_temp[fd])
		result = ft_append_line(str_temp[fd]);
	str_temp[fd] = ft_clear_line(str_temp[fd]);
	return (result);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char	*line;
	int		i;
	int		fd1;
//	int		fd2;
	fd1 = open("empty.txt", O_RDONLY);
//	fd2 = open("txtfile2.txt", O_RDONLY);
	i = 1;
	while (i < 3)
	{
		line = get_next_line(fd1);
		printf("ligne %d:%s", i, line);
		free(line);
//		line = get_next_line(fd2);
//		printf("ligne %d:%s", i, line);
//		free(line);
		i++;
	}
	close(fd1);
//	close(fd2);
	return (0);
}*/
