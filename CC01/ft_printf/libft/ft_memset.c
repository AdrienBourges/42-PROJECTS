#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char *result;

	result = ptr;
	while (n > 0)
	{
		*result = c;
		result++;
		n--;
	}
	return (ptr);
}
/*
#include <stdio.h>

int main()
{
    char str[20] = "Hello, World!";
    int num[5] = {1, 2, 3, 4, 5};
    printf("Before memset: %s\n", str);
    ft_memset(str, '*', 5);
    printf("After memset: %s\n", str);
	printf("\n");
    ft_memset(num, 0, sizeof(num));
    printf("After memset: ");
    for (int i = 0; i < 5; i++)
	{
        printf("%d", num[i]);
    }
}

If we use a pointer of type char*, and if char is signed on a particular system, it means the range of values a char variable can hold might be from -128 to 127.
However, if we use a pointer of type unsigned char*, it ensures that each byte is treated as an independent value ranging from 0 to 255, without concerns about sign extension.

*/
