/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:23:50 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:23:51 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_reinit_data(t_algo_data *data)
{
	data -> nbr_index_a = 0;
	data -> nbr_index_b = 0;
	data -> move_count = 2147483647;
}

void	ft_newalgo2(int *true_tab, int *temp_tab, t_algo_data *data, t_lst **b)
{
	temp_tab[2] = data -> nbr_index_a;
	temp_tab[3] = ft_findpos(*b, ft_max(*b));
	ft_replace(true_tab, temp_tab, &data -> move_count);
}

void	ft_newalgo3(int *true_tab, int *temp_tab, t_algo_data *data)
{
	temp_tab[2] = data -> nbr_index_a;
	temp_tab[3] = data -> nbr_index_b + 1;
	ft_replace(true_tab, temp_tab, &data -> move_count);
}

void	ft_newalgo4(int *true_tab, int *temp_tab, t_algo_data *data)
{
	temp_tab[2] = data -> nbr_index_a;
	temp_tab[3] = 0;
	ft_replace(true_tab, temp_tab, &data -> move_count);
}

void	ft_decision(t_lst **b, int *true_tab, int *temp_tab, t_algo_data *d)
{
	while ((*b)-> next)
	{
		if (d -> number > ft_max(*b) || d -> number < ft_min(*b))
		{
			ft_newalgo2(true_tab, temp_tab, d, b);
			break ;
		}
		else if (d -> number < (*b)-> data && d -> number > (*b)-> next -> data)
		{
			ft_newalgo3(true_tab, temp_tab, d);
			break ;
		}
		else if (d -> number > (*b)-> data && d -> number < ft_last(*b))
		{
			ft_newalgo4(true_tab, temp_tab, d);
			break ;
		}
		*b = (*b)-> next;
		d -> nbr_index_b++;
	}
}
