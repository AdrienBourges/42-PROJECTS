/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:46:53 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 17:15:10 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			result++;
		while (*s && *s != c)
			s++;
	}
	return (result);
}

static char	*ft_create_word(char const *s, char c)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_len_word(s, c);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = *s++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	**ft_free_space(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	result = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (s && *s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			result[i] = ft_create_word(s, c);
			if (!result[i])
				return (ft_free_space(result, i));
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	result[i] = NULL;
	return (result);
}
