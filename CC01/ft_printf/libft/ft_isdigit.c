#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main()
{
        printf("%d",ft_isalpha(','));
}
*/
