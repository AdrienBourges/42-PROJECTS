#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
typedef struct s_lst
{
	struct s_lst	*next;
	int				data;
}	t_lst;

t_lst *ft_init(char **argv);
void ft_swap(t_lst *head, char c);
void ft_newalgo(t_lst **astack, t_lst **bstack);
t_lst *ft_newnode(int data, t_lst *stack, char **tab);
void	ft_push_a (t_lst **head_a, t_lst **head_b);
void	ft_push_b(t_lst **head_a, t_lst **head_b);
void	ft_add_node(t_lst **head, int data, char **tab);
void	ft_reverse_rotate(t_lst **head, char c);
void 	ft_rotate(t_lst **head, char c);
void ft_divide(int argc, t_lst **head_a, t_lst **head_b);
void	ft_sswap(t_lst *head_a, t_lst *head_b);

void	ft_rreverse_rotate(t_lst **head_a, t_lst **head_b);
void	ft_rrotate(t_lst **head_a, t_lst **head_b);\

void ft_sort(int argc, t_lst **head_a, t_lst **head_b);

void print_stack(t_lst *head); 
int ft_amoi(char *str, t_lst *stack, char **tab);
void ft_exit(t_lst *stack, char **tab);
void ft_free(t_lst *stack);

#endif
