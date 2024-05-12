int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb >= 0 && nb <= 12)
	{
		while (nb > 0)
		{
			result *= nb;
			nb--;
		}
		return (result);
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d",ft_iterative_factorial(12));
}*/
