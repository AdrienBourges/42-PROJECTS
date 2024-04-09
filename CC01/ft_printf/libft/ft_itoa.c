#include "libft.h"

static	int	ft_count_size(long nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static void	ft_addnumber(char *result, long nbr, int size)
{
	int	temp;

	temp = size;
	if (nbr < 0)
	{
		nbr = -nbr;
		result[0] = '-';
	}
	while (nbr > 0)
	{
		result[size - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		size--;
	}
	result[temp] = '\0';
}

char	*ft_zero(void)
{
	char	*result;

	result = malloc(2);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*result;
	int		size;

	nbr = n;
	size = ft_count_size(nbr);
	if (nbr == 0)
		return (ft_zero());
	result = malloc(ft_count_size(nbr) + 1);
	if (!result)
		return (NULL);
	ft_addnumber(result, nbr, size);
	return (result);
}
/*
#include <stdio.h>

int main()
{
	printf("%s", ft_itoa(-444));
}*/	
