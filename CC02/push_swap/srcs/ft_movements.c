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
