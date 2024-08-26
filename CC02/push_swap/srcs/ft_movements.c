/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:29:50 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 17:29:52 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_swap(t_lst *head, char c)
{
	int	temp;

	if (head == NULL || head -> next == NULL)
		return ;
	temp = head -> data;
	head -> data = head -> next -> data;
	head -> next -> data = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_sswap(t_lst *head_a, t_lst *head_b)
{
	ft_swap(head_a, 0);
	ft_swap(head_b, 0);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_lst **head_a, t_lst **head_b)
{
	t_lst	*temp;

	if (head_b == NULL || *head_b == NULL)
		return ;
	temp = *head_b;
	*head_b = temp -> next;
	temp -> next = *head_a;
	*head_a = temp;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_lst **head_a, t_lst **head_b)
{
	t_lst	*temp;

	if (head_a == NULL || *head_a == NULL)
		return ;
	temp = *head_a;
	*head_a = temp -> next;
	temp -> next = *head_b;
	*head_b = temp;
	write(1, "pb\n", 3);
}
