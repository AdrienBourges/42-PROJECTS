/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:37:06 by abourges          #+#    #+#             */
/*   Updated: 2024/08/26 18:31:02 by abourges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_lst
{
	struct s_lst	*next;
	int				data;
}	t_lst;

typedef struct s_algo_data
{
	int	move_count;
	int	nbr_index_a;
	int	nbr_index_b;
	int	number;
}	t_algo_data;

typedef struct s_exec_data
{
	int	rotate_a;
	int	r_rotate_a;
	int	rotate_b;
	int	r_rotate_b;
}	t_exec_data;

t_lst	*ft_init(char **argv);
void	ft_swap(t_lst *head, char c);
void	ft_newalgo(t_lst **astack, t_lst **bstack);
t_lst	*ft_newnode(int data, t_lst *stack, char **tab);
void	ft_push_a(t_lst **head_a, t_lst **head_b);
void	ft_push_b(t_lst **head_a, t_lst **head_b);
void	ft_add_node(t_lst **head, int data, char **tab);
void	ft_reverse_rotate(t_lst **head, char c);
void	ft_rotate(t_lst **head, char c);
void	ft_divide(int argc, t_lst **head_a, t_lst **head_b);
void	ft_sswap(t_lst *head_a, t_lst *head_b);
void	ft_rreverse_rotate(t_lst **head_a, t_lst **head_b);
void	ft_rrotate(t_lst **head_a, t_lst **head_b);
void	ft_sort(int argc, t_lst **head_a, t_lst **head_b);
void	print_stack(t_lst *head);
int		ft_amoi(char *str, t_lst *stack, char **tab);
void	ft_exit(t_lst *stack, char **tab);
void	ft_free(t_lst *stack);
void	ft_rotate(t_lst **head, char c);
void	ft_rrotate(t_lst **head_a, t_lst **head_b);
void	ft_reverse_rotate(t_lst **head, char c);
void	ft_rreverse_rotate(t_lst **head_a, t_lst **head_b);
void	ft_free(t_lst *stack);
void	free_tab(char **tab);
void	ft_exit(t_lst *stack, char **tab);
void	check_exit(char *str, t_lst *stack, char **tab, int index);
int		ft_max(t_lst *stack);
int		ft_min(t_lst *stack);
int		ft_stacksize(t_lst *stack);
int		ft_findpos(t_lst *bstack, int number);
int		ft_last(t_lst *stack);
int		ft_move_counter_2(int ra, int rb, int rra, int rrb);
int		ft_move_counter(int *tab);
void	ft_set_a(int *rotate_a, int *r_rotate_a, int *tab);
void	ft_set_b(int *rotate_b, int *r_rotate_b, int *tab);
void	ft_double_rota(int *r1, int *rotate2, t_lst **astack, t_lst **bstack);
void	ft_double_rrota(int *r1, int *rotate2, t_lst **astack, t_lst **bstack);
void	ft_rota(int ra, int rb, t_lst **astack, t_lst **bstack);
void	ft_r_rota(int rra, int r_rotate_b, t_lst **astack, t_lst **bstack);
void	ft_init_exec(t_exec_data *data, int *tab);
void	ft_execute(t_lst **astack, t_lst **bstack, int *tab);
void	ft_sort_a_2(int pos_min, t_lst **astack);
void	ft_sort_a(t_lst **astack);
void	ft_repush2(int pos_max_b, int size_b, t_lst **bstack);
void	ft_repush(t_lst **astack, t_lst **bstack);
void	ft_inits(t_lst **a, t_lst **b, int **true_tab, int **temp_tab);
void	ft_reinit_data(t_algo_data *data);
void	ft_newalgo2(int *true_tab, int *temp_tab, t_algo_data *data, t_lst **b);
void	ft_newalgo3(int *true_tab, int *temp_tab, t_algo_data *data);
void	ft_newalgo4(int *true_tab, int *temp_tab, t_algo_data *data);
void	ft_decision(t_lst **b, int *true_tab, int *temp_tab, t_algo_data *d);
void	ft_tabs(t_lst **astack, t_lst **bstack, int *true_tab, int *temp_tab);
void	ft_replace(int *true_tab, int *temp_tab, int *move_count);
void	ft_finish(t_lst **astack, t_lst **bstack, int *true_tab, int *temp_tab);
void	ft_reinit_data2(t_algo_data *data);
void	ft_newalgo(t_lst **astack, t_lst **bstack);

#endif
