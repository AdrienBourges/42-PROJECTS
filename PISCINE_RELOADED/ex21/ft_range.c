#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;

	if (min >= max)
		return (NULL);
	if (!(result = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (max >= min)
	{
		result[max - min - 1] = max - 1;
		max--;
	}
	return (result);
}
