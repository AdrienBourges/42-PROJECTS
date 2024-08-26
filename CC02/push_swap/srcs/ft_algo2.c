/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:29:48 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:29:49 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

int	ft_max(t_lst *stack)
{
	int	max;

	max = stack -> data;
	while (stack)
	{
		if (max < stack -> data)
			max = stack -> data;
		stack = stack -> next;
	}
	return (max);
}

int	ft_min(t_lst *stack)
{
	int	min;

	min = stack -> data;
	while (stack)
	{
		if (min > stack -> data)
			min = stack -> data;
		stack = stack -> next;
	}
	return (min);
}

int	ft_stacksize(t_lst *stack)
{
	int	result;

	result = 0;
	while (stack)
	{
		result++;
		stack = stack -> next;
	}
	return (result);
}

int	ft_findpos(t_lst *bstack, int number)
{
	int	index;

	index = 0;
	while (bstack -> data != number)
	{
		index++;
		bstack = bstack -> next;
	}
	return (index);
}

int	ft_last(t_lst *stack)
{
	int	last;

	while (stack -> next)
	{
		stack = stack -> next;
	}
	last = stack -> data;
	return (last);
}
