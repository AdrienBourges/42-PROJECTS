/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:56 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:20:58 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_sort_a_2(int pos_min, t_lst **astack)
{
	if (pos_min == 1)
		ft_rotate(astack, 'a');
	if (pos_min == 2)
	{
		ft_swap(*astack, 'a');
		ft_reverse_rotate(astack, 'a');
	}
}

void	ft_sort_a(t_lst **astack)
{
	int	max;
	int	pos_max;
	int	min;
	int	pos_min;

	max = ft_max(*astack);
	pos_max = ft_findpos(*astack, max);
	min = ft_min(*astack);
	pos_min = ft_findpos(*astack, min);
	if (pos_max == 2 && pos_min == 1)
		ft_swap(*astack, 'a');
	if (pos_max == 1)
	{
		ft_reverse_rotate(astack, 'a');
		if (pos_min == 0)
			ft_swap(*astack, 'a');
	}
	if (pos_max == 0)
		ft_sort_a_2(pos_min, astack);
}

void	ft_repush2(int pos_max_b, int size_b, t_lst **bstack)
{
	if (pos_max_b <= size_b / 2)
	{
		while (pos_max_b-- > 0)
			ft_rotate(bstack, 'b');
	}
	else
	{
		while (pos_max_b++ < size_b)
			ft_reverse_rotate(bstack, 'b');
	}
}

void	ft_repush(t_lst **astack, t_lst **bstack)
{
	int	size_b;
	int	max_b;
	int	pos_max_b;
	int	tab[3];
	int	i;

	if (!bstack || !*bstack)
		return ;
	size_b = ft_stacksize(*bstack);
	max_b = ft_max(*bstack);
	pos_max_b = ft_findpos(*bstack, max_b);
	tab[0] = ft_max(*astack);
	tab[1] = (*astack)-> next-> data;
	tab[2] = ft_min(*astack);
	ft_repush2(pos_max_b, size_b, bstack);
	i = 0;
	while (i < 3)
	{
		while (bstack && (*bstack) && (*bstack)-> data > tab[i])
			ft_push_a(astack, bstack);
		i++;
		ft_reverse_rotate(astack, 'a');
	}
	while (*bstack)
		ft_push_a(astack, bstack);
}

void	ft_inits(t_lst **a, t_lst **b, int **true_tab, int **temp_tab)
{
	*true_tab = malloc(sizeof(int) * 4);
	if (!*true_tab)
		ft_exit(*a, 0);
	*temp_tab = malloc(sizeof(int) * 4);
	if (!*temp_tab)
	{
		free(*true_tab);
		ft_exit(*a, 0);
	}
	if (ft_stacksize(*a) > 3 && ft_stacksize(*a) != 4)
	{
		ft_push_b(a, b);
		ft_push_b(a, b);
	}
	else if (ft_stacksize(*a) == 4)
		ft_push_b(a, b);
}
