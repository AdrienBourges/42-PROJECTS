#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp;
	unsigned char		*temp2;

	if (!dest && !src)
		return (0);
	temp = src;
	temp2 = dest;
	if (dest > src)
	{
		temp = src + n;
		temp2 = dest + n;
		while (n-- > 0)
			*--temp2 = *--temp;
	}
	else
	{
		while (n-- > 0)
			*temp2++ = *temp++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char source[] = "Salut";
	char destination[20];

	// Test sans overlap theorique
	ft_memmove(destination, source, strlen(source) + 1);
	printf("Destination apres ft_memmove (sans overlap): %s\n", destination);

	// Test avec overlap
	ft_memmove(destination + 3, destination, strlen(destination) + 1);
	printf("Destination apres ft_memmove (overlap): %s\n", destination);

	return 0;
}*/

// Cet exo aborde les problemes d'ordre dans lesquels sont rangees les adresses memoires. 
// dans le cas ou src a une adresse memoire plus basse que dest il y a possibilite d'overlap
// si on ne gere pas le cas d'overlap on va vouloir copier la source dans la dest mais la source sera modifiee au fur et a mesure ce qui va corrompre la data.
// on gere le cas d'overlap en copiant par la fin, la source sera aussi modifiee au fur et a mesure, plus explicite en passant au debugger
