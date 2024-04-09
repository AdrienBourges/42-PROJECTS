#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp;
	unsigned char		*temp2;

	if (!dest && !src)
		return (0);
	temp = src;
	temp2 = dest;
	while (n > 0)
	{
		*temp2 = *temp;
		temp2++;
		temp++;
		n--;
	}
	return (dest);
}
/*

#include <string.h>
#include <stdio.h>

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    memcpy(destination, source, 5);
    printf("Destination after standard memcpy: %s\n", destination);

    // Using your memcpy implementation
    ft_memcpy(destination, source, 5);
    printf("Destination after your memcpy: %s\n", destination);

    return 0;
}
*/
/*
 In C, you can implicitly convert from const void * to const unsigned char * without casting, because void * and unsigned char * are compatible pointer types, and the const qualifier is preserved in the conversion.

 */
