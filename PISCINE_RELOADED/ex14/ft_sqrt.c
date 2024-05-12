int	ft_sqrt(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (result * result < nb && result < 46340)
		result++;
	if (result * result == nb)
		return (result);
	return (0);
}
/*
#include <stdio.h>

int main()
{
	printf("%d",ft_sqrt(2147483647));
}*/
