#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_is_newline(char *line) // fct qui permet de detecter si on a une newline dans notre char *, auquel cas on arrete de read dans ft_stock_text
{
	if (!line)
		return (0);
	while (*line != '\n')
	{
		if (!*line)
			return (0);
		line++;
	}
	return (1);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_merge(char *s1, char *s2)
{
	char	*result;
	size_t	total_size;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	total_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_size + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}
