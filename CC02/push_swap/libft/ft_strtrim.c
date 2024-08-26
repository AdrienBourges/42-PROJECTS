/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:55:28 by abourges          #+#    #+#             */
/*   Updated: 2024/05/21 12:55:11 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && j > i && ft_strchr(set, s1[j - 1]))
		j--;
	result = malloc(j - i + 1);
	if (!result)
		return (NULL);
	while (j > (i + k))
	{
		result[k] = s1[i + k];
		k++;
	}
	result[k] = '\0';
	return (result);
}
