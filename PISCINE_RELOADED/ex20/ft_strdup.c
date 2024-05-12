#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc (ft_strlen(src) + 1);
	if (!result)
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
/*
#include <stdio.h>

int main()
{
	printf("%s", ft_strdup("abcdefg"));
}
*/
