/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:36:56 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:58 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_free(t_lst *stack)
{
	t_lst	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack -> next;
		free(tmp);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_exit(t_lst *stack, char **tab)
{
	int	i;

	i = 0;
	ft_free(stack);
	write(2, "Error\n", 6);
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	exit(1);
}

void	check_exit(char *str, t_lst *stack, char **tab, int index)
{
	if (!str[index])
		ft_exit(stack, tab);
}
