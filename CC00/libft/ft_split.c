#include "libft.h"

static size_t	ft_len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			result++;
		while (*s && *s != c)
			s++;
	}
	return (result);
}

static char	*ft_create_word(char const *s, char c)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_len_word(s, c);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = *s++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_free_space(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	if (!(result = malloc((ft_countwords(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			result[i] = ft_create_word(s, c);
			if (!result[i])
			{
				ft_free_space(result, i);
				return (NULL);
			}
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	result[i] = NULL;
	return (result);
}
