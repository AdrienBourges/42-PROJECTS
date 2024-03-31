#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && i < len && little[j])
			{
				i++;
				j++;
			}
			if (!little[j])
				return ((char *)big + i - j);
			i = i - j;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>


int main() {
	// Test case 1: Basic case - "world" found within the first 16 characters of "Hello word world"
	char *result1_ft = ft_strnstr("Hello word world", "world", 16);
	printf("Test case 1: %s (Expected: 'world' starting at position 6)\n", result1_ft);

	// Test case 2: "world" found within the first 5 characters of "Hello word world"
	char *result2_ft = ft_strnstr("Hello word world", "world", 5);
	printf("Test case 2: %s (Expected: NULL, 'world' cannot be found within the first 5 characters)\n", result2_ft);

	// Test case 3: "world" found within the first 20 characters of "Hello word world"
	char *result3_ft = ft_strnstr("Hello word world", "world", 20);
	printf("Test case 3: %s (Expected: 'world' starting at position 6)\n", result3_ft);

	// Test case 4: "world" not found within the first 3 characters of "Hello word world"
	char *result4_ft = ft_strnstr("Hello word world", "world", 3);
	printf("Test case 4: %s (Expected: NULL, 'world' cannot be found within the first 3 characters)\n", result4_ft);

	// Test case 5: Empty needle
	char *result5_ft = ft_strnstr("Hello word world", "", 16);
	printf("Test case 5: %s (Expected: Pointer to the beginning of the haystack string)\n", result5_ft);

	// Test case 6: Empty haystack
	char *result6_ft = ft_strnstr("", "world", 5);
	printf("Test case 6: %s (Expected: NULL, haystack is empty)\n", result6_ft);

	// Test case 7: "world" not found within the first 16 characters of "Hello word"
	char *result7_ft = ft_strnstr("Hello word", "world", 16);
	printf("Test case 7: %s (Expected: NULL, 'world' cannot be found within the first 16 characters)\n", result7_ft);

	// Test case 8: "world" found within the entire string "world"
	char *result8_ft = ft_strnstr("world", "world", 5);
	printf("Test case 8: %s (Expected: Pointer to the beginning of the haystack string)\n", result8_ft);

	return 0;
}
*/
