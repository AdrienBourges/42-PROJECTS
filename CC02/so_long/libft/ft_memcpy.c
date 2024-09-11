/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:49:41 by abourges          #+#    #+#             */
/*   Updated: 2024/05/13 17:49:44 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
