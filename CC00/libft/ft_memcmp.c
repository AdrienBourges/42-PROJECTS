#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp;
	const unsigned char	*temp2;

	temp = (const unsigned char *) s1;
	temp2 = (const unsigned char *) s2;
	while (n > 0)
	{
		if (*temp != *temp2)
			return ((unsigned char)*temp - (unsigned char)*temp2);
		temp++;
		temp2++;
		n--;
	}
	return (0);
}
