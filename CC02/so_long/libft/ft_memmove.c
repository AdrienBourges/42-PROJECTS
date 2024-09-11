/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:50:04 by abourges          #+#    #+#             */
/*   Updated: 2024/05/13 17:50:09 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
