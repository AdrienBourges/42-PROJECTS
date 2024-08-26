/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:36:49 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:51 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

int	ft_amoi(char *str, t_lst *stack, char **tab)
{
	long long	result;
	int			i;
	int			sign;

	sign = 1;
	result = 0;
	i = 0;
	check_exit(str, stack, tab, i);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	check_exit(str, stack, tab, i);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit(stack, tab);
		result = (result * 10) + (str[i] - 48);
		if (result * sign > 2147483647 || result * sign < -2147483648)
			ft_exit(stack, tab);
		i++;
	}
	return ((int) result * sign);
}

int	ft_is_ordered(t_lst *astack)
{
	while (astack -> next)
	{
		if (astack -> data > astack -> next -> data)
			return (0);
		astack = astack -> next;
	}
	return (1);
}

char	**check_args(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(argc * sizeof(char *));
	if (!tab)
		ft_exit(0, 0);
	while (argv[i + 1])
	{
		tab[i] = ft_strdup(argv[i + 1]);
		if (!tab[i])
			ft_exit(0, tab);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(int argc, char **argv)
{
	t_lst	*astack;
	t_lst	*bstack;
	char	**tab;

	if (argc <= 1)
		exit(1);
	else if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab || !tab[0])
			ft_exit(0, 0);
	}
	else
		tab = check_args(argc, argv);
	bstack = NULL;
	astack = ft_init(tab);
	free_tab(tab);
	if (ft_is_ordered(astack) == 1)
	{
		ft_free(astack);
		exit(1);
	}
	ft_newalgo(&astack, &bstack);
	ft_free(astack);
	ft_free(bstack);
}
