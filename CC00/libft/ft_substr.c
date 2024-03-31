#include "libft.h"
//#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = 0;
	if (ft_strlen(s) > start)
	{
		while (s[start + size] && size < len)
			size++;
	}
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>

int main()
{
	printf("%s", ft_substr("hola", 4294967295, 0));
}
*/
