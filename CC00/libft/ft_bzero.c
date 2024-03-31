#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, '\0', n);
}
/*

#include <stdio.h>

int main()
{
		char str[20] = "Hello, World!";
		int num[5] = {1, 2, 3, 4, 5};
		printf("Before memset: %s\n", str);
		ft_bzero(str, 5);
		printf("After memset: %s\n", str);
		printf("\n");
		ft_bzero(num, sizeof(num));
		printf("After memset: ");
		for (int i = 0; i < 5; i++)
		{
				printf("%d", num[i]);
		}
}

*/
