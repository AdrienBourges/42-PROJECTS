#include "../includes/pipex.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

int	count_arguments(char *cmd)
{
	int	count;

	count = 0;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (*cmd != '\0')
		{
			count++;
			while (*cmd && *cmd != ' ')
				cmd++;
		}
	}
	return (count);
}

char	*append_newline(char *str)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	ft_strcpy(new_str, str);
	new_str[len] = '\n';
	new_str[len + 1] = '\0';
	return (new_str);
}
