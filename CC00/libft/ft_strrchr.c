#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	while (len > 0 && *s != c)
	{
		s--;
		len--;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
