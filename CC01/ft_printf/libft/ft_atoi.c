#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result *= 10;
		result += ptr[i] - 48;
		i++;
	}
	return (result * sign);
}
