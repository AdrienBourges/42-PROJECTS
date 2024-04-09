#include "libft.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc (nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
