/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:19:14 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:19:16 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_double_rrota(int *r1, int *rotate2, t_lst **astack, t_lst **bstack)
{
	int	double_rotate;

	double_rotate = *r1;
	*rotate2 -= double_rotate;
	while (double_rotate-- > 0)
		ft_rreverse_rotate(astack, bstack);
	*r1 = 0;
}

void	ft_rota(int ra, int rb, t_lst **astack, t_lst **bstack)
{
	while (ra > 0)
	{
		ft_rotate(astack, 'a');
		ra--;
	}
	while (rb > 0)
	{
		ft_rotate(bstack, 'b');
		rb--;
	}
}

void	ft_r_rota(int rra, int r_rotate_b, t_lst **astack, t_lst **bstack)
{
	while (rra > 0)
	{
		ft_reverse_rotate(astack, 'a');
		rra--;
	}
	while (r_rotate_b > 0)
	{
		ft_reverse_rotate(bstack, 'b');
		r_rotate_b--;
	}
	ft_push_b(astack, bstack);
}

void	ft_init_exec(t_exec_data *data, int *tab)
{
	data -> rotate_a = 0;
	data -> r_rotate_a = 0;
	data -> rotate_b = 0;
	data -> r_rotate_b = 0;
	ft_set_a(&data -> rotate_a, &data -> r_rotate_a, tab);
	ft_set_b(&data -> rotate_b, &data -> r_rotate_b, tab);
}

void	ft_execute(t_lst **astack, t_lst **bstack, int *tab)
{
	t_exec_data	d;

	ft_init_exec(&d, tab);
	if (d.rotate_b >= d.rotate_a && d.r_rotate_b >= d.r_rotate_a)
	{
		ft_double_rota(&d.rotate_a, &d.rotate_b, astack, bstack);
		ft_double_rrota(&d.r_rotate_a, &d.r_rotate_b, astack, bstack);
	}
	else if (d.rotate_b <= d.rotate_a && d.r_rotate_b <= d.r_rotate_a)
	{
		ft_double_rota(&d.rotate_b, &d.rotate_a, astack, bstack);
		ft_double_rrota(&d.r_rotate_b, &d.r_rotate_a, astack, bstack);
	}
	else if (d.rotate_b >= d.rotate_a && d.r_rotate_b <= d.r_rotate_a)
	{
		ft_double_rota(&d.rotate_a, &d.rotate_b, astack, bstack);
		ft_double_rrota(&d.r_rotate_b, &d.r_rotate_a, astack, bstack);
	}
	else if (d.rotate_b <= d.rotate_a && d.r_rotate_b >= d.r_rotate_a)
	{
		ft_double_rota(&d.rotate_b, &d.rotate_a, astack, bstack);
		ft_double_rrota(&d.r_rotate_a, &d.r_rotate_b, astack, bstack);
	}
	ft_rota(d.rotate_a, d.rotate_b, astack, bstack);
	ft_r_rota(d.r_rotate_a, d.r_rotate_b, astack, bstack);
}
