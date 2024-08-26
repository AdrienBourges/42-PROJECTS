/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:29:28 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:30:15 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_tabs(t_lst **astack, t_lst **bstack, int *true_tab, int *temp_tab)
{
	int	size_a;
	int	size_b;

	size_a = ft_stacksize(*astack);
	size_b = ft_stacksize(*bstack);
	true_tab[0] = size_a;
	true_tab[1] = size_b;
	temp_tab[0] = size_a;
	temp_tab[1] = size_b;
}

void	ft_replace(int *true_tab, int *temp_tab, int *move_count)
{
	int	temp_counter;

	temp_counter = ft_move_counter(temp_tab);
	if (*move_count > temp_counter)
	{
		*move_count = temp_counter;
		true_tab[2] = temp_tab[2];
		true_tab[3] = temp_tab[3];
	}
}

void	ft_finish(t_lst **astack, t_lst **bstack, int *true_tab, int *temp_tab)
{
	ft_sort_a(astack);
	ft_repush(astack, bstack);
	free(temp_tab);
	free(true_tab);
}

void	ft_reinit_data2(t_algo_data *data)
{
	data -> nbr_index_a++;
	data -> nbr_index_b = 0;
}

void	ft_newalgo(t_lst **astack, t_lst **bstack)
{
	t_algo_data	data;
	t_lst		*tmp2;
	t_lst		*tmp3;
	int			*true_tab;
	int			*temp_tab;

	ft_inits(astack, bstack, &true_tab, &temp_tab);
	while (ft_stacksize(*astack) > 3)
	{
		ft_tabs(astack, bstack, true_tab, temp_tab);
		ft_reinit_data(&data);
		tmp2 = *bstack;
		tmp3 = *astack;
		while (*astack)
		{
			data.number = (*astack)-> data;
			ft_decision(bstack, true_tab, temp_tab, &data);
			*astack = (*astack)-> next;
			*bstack = tmp2;
			ft_reinit_data2(&data);
		}
		*astack = tmp3;
		ft_execute(astack, bstack, true_tab);
	}
	ft_finish(astack, bstack, true_tab, temp_tab);
}
