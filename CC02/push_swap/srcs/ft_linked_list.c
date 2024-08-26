/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:30:19 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 17:30:22 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

t_lst	*ft_newnode(int data, t_lst *stack, char **tab)
{
	t_lst	*result;

	result = malloc(sizeof(t_lst));
	if (!result)
		ft_exit(stack, tab);
	result->data = data;
	result -> next = NULL;
	return (result);
}

void	ft_add_node(t_lst **head, int data, char **tab)
{
	t_lst	*node;
	t_lst	*tmp;

	node = ft_newnode(data, *head, tab);
	if (!node)
		return ;
	if (!(*head))
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = node;
}

void	ft_checkdupes(t_lst *stack, int number, char **tab)
{
	t_lst	*tmp;

	tmp = stack;
	while (stack)
	{
		if (number == stack -> data)
		{
			stack = tmp;
			ft_exit(stack, tab);
		}
		stack = stack -> next;
	}
}

t_lst	*ft_init(char **tab)
{
	t_lst	*result;
	int		i;
	int		number;

	result = NULL;
	i = 0;
	while (tab[i])
	{
		number = ft_amoi(tab[i], result, tab);
		ft_checkdupes(result, number, tab);
		ft_add_node(&result, number, tab);
		i++;
	}
	return (result);
}
