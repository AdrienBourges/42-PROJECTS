/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:29:46 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 17:29:54 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

void	ft_rotate(t_lst **head, char c)
{
	t_lst	*temp;
	t_lst	*current;

	if (!head || !*head || !((*head)-> next))
		return ;
	temp = *head;
	current = *head;
	while (current -> next)
		current = current -> next;
	current -> next = temp;
	*head = temp -> next;
	temp -> next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rrotate(t_lst **head_a, t_lst **head_b)
{
	ft_rotate(head_a, 0);
	ft_rotate(head_b, 0);
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_lst **head, char c)
{
	t_lst	*temp;
	t_lst	*current;

	if (!*head || !head || !((*head)-> next))
		return ;
	current = *head;
	while (current -> next && current -> next ->next)
		current = current -> next;
	temp = current;
	current = current -> next;
	current -> next = *head;
	temp -> next = NULL;
	*head = current;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rreverse_rotate(t_lst **head_a, t_lst **head_b)
{
	ft_reverse_rotate(head_a, 0);
	ft_reverse_rotate(head_b, 0);
	write(1, "rrr\n", 4);
}
