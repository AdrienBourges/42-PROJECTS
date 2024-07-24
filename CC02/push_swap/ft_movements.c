#include "ft_pushswap.h"

void ft_swap(t_lst *head)
{
	int temp;

	if (head == NULL || head -> next == NULL)
		return ;
	temp = head -> data;
	head -> data = head -> next -> data;
	head -> next -> data = temp;
}

void	ft_sswap(t_lst *head_a, t_lst *head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
}

void	ft_push_a (t_lst **head_a, t_lst **head_b)
{
	t_lst *temp;

	if (head_b == NULL || *head_b == NULL)
		return ;
	temp = *head_b;
	*head_b = temp -> next;
	temp -> next = *head_a;
	*head_a = temp;
}

void	ft_push_b(t_lst **head_a, t_lst **head_b)
{
	t_lst *temp;

	if (head_a == NULL || *head_a == NULL)
		return ;
	temp = *head_a;
	*head_a = temp -> next;
	temp -> next = *head_b;
	*head_b = temp;
}

void 	ft_rotate(t_lst **head)
{
	t_lst *temp;
	t_lst *current;

	if (!head || !*head || !((*head) -> next))
		return ;
	temp = *head;
	current = *head;
	while (current -> next)
		current = current -> next;
	current -> next = temp;
	*head = temp -> next;
	temp -> next = NULL;
}

void	ft_rrotate(t_lst **head_a, t_lst **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
}

void	ft_reverse_rotate(t_lst **head)
{
	t_lst *temp;
	t_lst *current;

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
}

void	ft_rreverse_rotate(t_lst **head_a, t_lst **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
}





