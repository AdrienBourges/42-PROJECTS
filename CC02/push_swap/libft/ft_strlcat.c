/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:52:59 by abourges          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:04 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[j])
		j++;
	len_dest = j;
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (len_src + size);
	while (src[i] && i < (size - len_dest - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
