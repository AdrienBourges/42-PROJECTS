/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:29:56 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:29:57 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

int	ft_move_counter_2(int ra, int rb, int rra, int rrb)
{
	int	double_rotate;
	int	double_rrotate;

	if (rb >= ra && rrb >= rra)
	{
		double_rotate = ra;
		double_rrotate = rra;
		return (double_rotate + double_rrotate + (rb - ra) + (rrb - rra));
	}
	else if (rb <= ra && rrb <= rra)
	{
		double_rotate = rb;
		double_rrotate = rrb;
		return (double_rotate + double_rrotate + (ra - rb) + (rra - rrb));
	}
	else if (rb >= ra && rrb <= rra)
	{
		double_rotate = ra;
		double_rrotate = rrb;
		return (double_rotate + double_rrotate + (rb - ra) + (rra - rrb));
	}
	double_rotate = rb;
	double_rrotate = rra;
	return (double_rotate + double_rrotate + (ra - rb) + (rrb - rra));
}

int	ft_move_counter(int *tab)
{
	int	rotate_a;
	int	r_rotate_a;
	int	rotate_b;
	int	r_rotate_b;

	rotate_a = 0;
	r_rotate_a = 0;
	rotate_b = 0;
	r_rotate_b = 0;
	if (tab[2] > (tab[0] / 2))
		r_rotate_a = tab[0] - tab[2];
	else if (tab[2] <= (tab[0] / 2))
		rotate_a = tab[2];
	if (tab[3] > (tab[1] / 2))
		r_rotate_b = tab[1] - tab[3];
	else if (tab[3] <= (tab[1] / 2))
		rotate_b = tab[3];
	return (ft_move_counter_2(rotate_a, rotate_b, r_rotate_a, r_rotate_b));
}

void	ft_set_a(int *rotate_a, int *r_rotate_a, int *tab)
{
	if (tab[2] > (tab[0] / 2))
	{
		*r_rotate_a = tab[0] - tab[2];
		*rotate_a = 0;
	}
	else if (tab[2] <= (tab[0] / 2))
	{
		*rotate_a = tab[2];
		*r_rotate_a = 0;
	}
}

void	ft_set_b(int *rotate_b, int *r_rotate_b, int *tab)
{
	if (tab[3] > (tab[1] / 2))
	{
		*r_rotate_b = tab[1] - tab[3];
		rotate_b = 0;
	}
	else if (tab[3] <= (tab[1] / 2))
	{
		*rotate_b = tab[3];
		*r_rotate_b = 0;
	}
}

void	ft_double_rota(int *r1, int *rotate2, t_lst **astack, t_lst **bstack)
{
	int	double_rotate;

	double_rotate = *r1;
	*rotate2 -= double_rotate;
	while (double_rotate-- > 0)
		ft_rrotate(astack, bstack);
	*r1 = 0;
}
