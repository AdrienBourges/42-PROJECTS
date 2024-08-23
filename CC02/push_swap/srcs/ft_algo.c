#include "../includes/ft_pushswap.h"


int ft_max(t_lst *stack)
{
	int max;

	max = stack -> data;
	while(stack)
	{
		if (max < stack -> data)
			max = stack -> data;
		stack = stack -> next;
	}
	return max;
}


int ft_min(t_lst *stack)
{
	int min;

	min = stack -> data;
	while(stack)
	{
		if (min > stack -> data)
			min = stack -> data;
		stack = stack -> next;
	}
	return min;
}

int ft_stacksize(t_lst *stack)
{
	int result;

	result = 0;
	while (stack)
	{
		result++;
		stack = stack -> next;
	}
	return result;
}

int ft_findpos(t_lst *bstack, int number)
{
	int index;

	index = 0;
	while (bstack -> data != number)
	{
		index++;
		bstack = bstack -> next;
	}
	return index;
}

int ft_last(t_lst *stack)
{
	int last;

	while (stack -> next)
	{
		stack = stack -> next;
	}
	last = stack -> data;
	return last;
}

int ft_move_counter_2(int rotate_a, int rotate_b, int r_rotate_a, int r_rotate_b)
{
	int double_rotate;
	int double_rrotate;

	if (rotate_b >= rotate_a && r_rotate_b >= r_rotate_a)
	{
		double_rotate = rotate_a;
		double_rrotate = r_rotate_a;
		return (double_rotate + double_rrotate + (rotate_b - rotate_a) + (r_rotate_b - r_rotate_a));
	}
	else if (rotate_b <= rotate_a && r_rotate_b <= r_rotate_a)
	{	
		double_rotate = rotate_b;
		double_rrotate = r_rotate_b;
		return (double_rotate + double_rrotate + (rotate_a - rotate_b) + (r_rotate_a - r_rotate_b));
	}
	else if (rotate_b >= rotate_a && r_rotate_b <= r_rotate_a)
	{
		double_rotate = rotate_a;
		double_rrotate = r_rotate_b;
		return (double_rotate + double_rrotate + (rotate_b - rotate_a) + (r_rotate_a - r_rotate_b));
	}
	double_rotate = rotate_b;
	double_rrotate = r_rotate_a;
	return (double_rotate + double_rrotate + (rotate_a - rotate_b) + (r_rotate_b - r_rotate_a));
}

int ft_move_counter(int *tab)
{
	//int move_count;
	int rotate_a;
	int r_rotate_a;
	int rotate_b;
	int r_rotate_b;
//	int double_rotate;
	//int double_rrotate;

	rotate_a = 0;
	r_rotate_a = 0;
	rotate_b = 0;
	r_rotate_b = 0;
	//move_count = 0;
	//ici on compte le nombre de move pour mettre le nombre desire au top de la stack A;
	if (tab[2] > (tab[0] / 2))
		r_rotate_a = tab[0] - tab[2];
	else if (tab[2] <= (tab[0] / 2))
		rotate_a = tab[2];

	if (tab[3] > (tab[1] / 2))
		r_rotate_b = tab[1] - tab[3];
	else if(tab[3] <= (tab[1] / 2))
		rotate_b = tab[3];
	return ft_move_counter_2(rotate_a, rotate_b, r_rotate_a, r_rotate_b);;
}

void ft_set_a(int *rotate_a, int *r_rotate_a, int *tab)
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

void ft_set_b(int *rotate_b, int *r_rotate_b, int *tab)
{
	if (tab[3] > (tab[1] / 2))
	{
		*r_rotate_b = tab[1] - tab[3];
		rotate_b = 0;
	}
	else if(tab[3] <= (tab[1] / 2))
	{
		*rotate_b = tab[3];
		*r_rotate_b = 0;
	}
}

void ft_double_rota (int *rotate1, int *rotate2, t_lst **astack, t_lst **bstack)
{
	int double_rotate;

	double_rotate = *rotate1;
	*rotate2 -= double_rotate;
	while (double_rotate-- > 0)
		ft_rrotate(astack, bstack);
	*rotate1 = 0;
}


void ft_double_rrota (int *rotate1, int *rotate2, t_lst **astack, t_lst **bstack)
{
	int double_rotate;

	double_rotate = *rotate1;
	*rotate2 -= double_rotate;
	while (double_rotate-- > 0)
		ft_rreverse_rotate(astack, bstack);
	*rotate1 = 0;
}

void ft_rota(int rotate_a, int rotate_b, t_lst **astack, t_lst **bstack)
{

	while (rotate_a > 0)
	{
		ft_rotate(astack, 'a');
		rotate_a--;
	}
	while (rotate_b > 0)
	{
		ft_rotate(bstack, 'b');
		rotate_b--;
	}
}

void ft_r_rota(int r_rotate_a, int r_rotate_b, t_lst **astack, t_lst **bstack)
{
	while (r_rotate_a > 0)
	{
		ft_reverse_rotate(astack, 'a');
		r_rotate_a--;
	}
	while (r_rotate_b > 0)
	{
		ft_reverse_rotate(bstack, 'b');
		r_rotate_b--;
	}
	ft_push_b(astack, bstack);
}

typedef struct s_exec_data { 
	int rotate_a;
	int r_rotate_a;
	int rotate_b;
	int r_rotate_b;
	} t_exec_data;

void ft_execute(t_lst **astack, t_lst **bstack, int *tab)
{

	// faire une struct est surement la solution
	int rotate_a;
	int r_rotate_a;
	int rotate_b;
	int r_rotate_b;

	rotate_a = 0;
	r_rotate_a = 0;
	rotate_b = 0;
	r_rotate_b = 0;
	//t_exec_data data;

	ft_set_a(&rotate_a, &r_rotate_a, tab);
	ft_set_b(&rotate_b, &r_rotate_b, tab);
	if (rotate_b >= rotate_a && r_rotate_b >= r_rotate_a)
	{
		ft_double_rota(&rotate_a, &rotate_b, astack, bstack);
		ft_double_rrota(&r_rotate_a, &r_rotate_b, astack, bstack);
	}
	else if (rotate_b <= rotate_a && r_rotate_b <= r_rotate_a)
	{	
		ft_double_rota(&rotate_b, &rotate_a, astack, bstack);
		ft_double_rrota(&r_rotate_b, &r_rotate_a, astack, bstack);
	}
	else if (rotate_b >= rotate_a && r_rotate_b <= r_rotate_a)
	{	
		ft_double_rota(&rotate_a, &rotate_b, astack, bstack);
		ft_double_rrota(&r_rotate_b, &r_rotate_a, astack, bstack);
	}
	else if (rotate_b <= rotate_a && r_rotate_b >= r_rotate_a)
	{
		ft_double_rota(&rotate_b, &rotate_a, astack, bstack);
		ft_double_rrota(&r_rotate_a, &r_rotate_b, astack, bstack);
	}
	ft_rota(rotate_a, rotate_b, astack, bstack);
	ft_r_rota(r_rotate_a, r_rotate_b, astack, bstack);
}


/*void ft_execute2(t_lst **astack, t_lst **bstack, int *tab)
{
	t_exec_data data;

	data.rotate_a = 0;
	data.r_rotate_a = 0;
	data.rotate_b = 0;
	data.r_rotate_b = 0;
	ft_set_a(&data.rotate_a, &data.r_rotate_a, tab);
	ft_set_b(&data.rotate_b, &data.r_rotate_b, tab);
	if (data.rotate_b >= data.rotate_a && data.r_rotate_b >= data.r_rotate_a)
	{
		ft_double_rota(&data.rotate_a, &data.rotate_b, astack, bstack);
		ft_double_rrota(&data.r_rotate_a, &data.r_rotate_b, astack, bstack);
	}
	else if (data.rotate_b <= data.rotate_a && data.r_rotate_b <= data.r_rotate_a)
	{	
		ft_double_rota(&data.rotate_b, &data.rotate_a, astack, bstack);
		ft_double_rrota(&data.r_rotate_b, &data.r_rotate_a, astack, bstack);
	}
	else if (data.rotate_b >= data.rotate_a && data.r_rotate_b <= data.r_rotate_a)
	{	
		ft_double_rota(&data.rotate_a, &data.rotate_b, astack, bstack);
		ft_double_rrota(&data.r_rotate_b, &data.r_rotate_a, astack, bstack);
	}
	else if (data.rotate_b <= data.rotate_a && data.r_rotate_b >= data.r_rotate_a)
	{
		ft_double_rota(&data.rotate_b, &data.rotate_a, astack, bstack);
		ft_double_rrota(&data.r_rotate_a, &data.r_rotate_b, astack, bstack);
	}
	ft_rota(data.rotate_a, data.rotate_b, astack, bstack);
	ft_r_rota(data.r_rotate_a, data.r_rotate_b, astack, bstack);

}*/


void ft_sort_a_2(int pos_min, t_lst **astack)
{
	if (pos_min == 1)
		ft_rotate(astack, 'a');
	if (pos_min == 2)
	{
		ft_swap(*astack,'a');
		ft_reverse_rotate(astack,'a');
	}
}

void ft_sort_a(t_lst **astack)
{
	int max;
	int pos_max;
	int min;
	int pos_min;

	max = ft_max(*astack);
	pos_max = ft_findpos(*astack, max);
	min = ft_min(*astack);
	pos_min = ft_findpos(*astack, min);
	if (pos_max == 2 && pos_min == 1)
		ft_swap(*astack,'a');
	if (pos_max == 1)
	{
		ft_reverse_rotate(astack, 'a');
		if (pos_min == 0)
			ft_swap(*astack, 'a');
	}
	if (pos_max == 0)
		ft_sort_a_2(pos_min, astack);
}	

void ft_repush2(int pos_max_b, int size_b, t_lst **bstack)
{
	if (pos_max_b <= size_b / 2)
	{
		while (pos_max_b-- > 0)
			ft_rotate(bstack, 'b');
	}
	else
	{
		while (pos_max_b++ < size_b)
			ft_reverse_rotate(bstack, 'b');
	}
}

void ft_repush(t_lst **astack, t_lst **bstack)
{
	int size_b;
	int max_b;
	int pos_max_b;
	int tab[3];
	int i;

	if (!bstack || !*bstack)
		return ;
	size_b = ft_stacksize(*bstack);
	max_b = ft_max(*bstack);
	pos_max_b = ft_findpos(*bstack, max_b);
	tab[0] = ft_max(*astack);
	tab[1] = (*astack) -> next -> data;
	tab[2] = ft_min(*astack);
	ft_repush2(pos_max_b, size_b, bstack);
	i = 0;
	while(i < 3)
	{
		while (bstack && (*bstack) && (*bstack)-> data > tab[i])
			ft_push_a(astack, bstack);
		i++;
		ft_reverse_rotate(astack,'a');
	}
	while (*bstack)
		ft_push_a(astack, bstack);
}

void ft_init_bstack_and_tabs(t_lst **astack, t_lst **bstack, int **true_tab, int **temp_tab)
{
	*true_tab = malloc(sizeof(int) * 4); // tableau de la forme: {size_a, size_b, index_a, index_b};
	if (!*true_tab)
		ft_exit(*astack, 0);
	*temp_tab = malloc(sizeof(int) * 4);
	if (!*temp_tab)
	{
		free(*true_tab);
		ft_exit(*astack, 0);
	}
	if (ft_stacksize(*astack) > 3 && ft_stacksize(*astack) != 4)
	{
		ft_push_b(astack, bstack);
		ft_push_b(astack, bstack);	
	}
	else if (ft_stacksize(*astack) == 4)
		ft_push_b(astack, bstack);
}

void ft_tabs(t_lst **astack, t_lst **bstack, int *true_tab, int *temp_tab)
{
	int size_a;
	int size_b;

	size_a = ft_stacksize(*astack);
	size_b = ft_stacksize(*bstack);
	true_tab[0] = size_a;
	true_tab[1] = size_b;
	temp_tab[0] = size_a;
	temp_tab[1] = size_b;
}

void ft_replace(int *true_tab, int *temp_tab, int *move_count)
{
	int temp_counter;

	temp_counter = ft_move_counter(temp_tab);
	if (*move_count > temp_counter)
	{
		*move_count = temp_counter;
		true_tab[2] = temp_tab[2];
		true_tab[3] = temp_tab[3];
	}
}

typedef struct s_algo_data {
    int move_count;
    int nbr_index_a;
    int nbr_index_b;
	int number;
} t_algo_data;

void ft_reinit_data(t_algo_data *data)
{
	data -> nbr_index_a = 0;
	data -> nbr_index_b = 0;
	data -> move_count = 10000;
}

void ft_newalgo2(int *true_tab, int *temp_tab, t_algo_data *data, t_lst **bstack)
{
	temp_tab[2] = data -> nbr_index_a;
	temp_tab[3] = ft_findpos(*bstack, ft_max(*bstack));
	ft_replace(true_tab, temp_tab, &data -> move_count);
}


void ft_newalgo3(int *true_tab, int *temp_tab, t_algo_data *data)
{
	temp_tab[2] = data -> nbr_index_a;
	temp_tab[3] = data -> nbr_index_b + 1;
	ft_replace(true_tab, temp_tab, &data -> move_count);
}

void ft_newalgo4(int *true_tab, int *temp_tab, t_algo_data *data)
{
	temp_tab[2] = data -> nbr_index_a;
	temp_tab[3] = 0;
	ft_replace(true_tab, temp_tab, &data -> move_count);
}

void ft_decision_bstack(t_lst **bstack, int *true_tab, int *temp_tab, t_algo_data *data)
{
	while ((*bstack) -> next)
	{
		if (data->number > ft_max(*bstack) || data -> number < ft_min(*bstack))
		{
			ft_newalgo2(true_tab, temp_tab, data, bstack);  
			break;
		}
		else if (data -> number < (*bstack) -> data && data -> number > (*bstack) -> next -> data)
		{
			ft_newalgo3(true_tab, temp_tab, data);  
			break;
		}
		else if (data -> number >  (*bstack) -> data && data -> number	< ft_last(*bstack))
		{
			ft_newalgo4(true_tab, temp_tab, data);
			break;
		}
		*bstack = (*bstack) -> next;
		data -> nbr_index_b++;
	 }
}

void ft_finish( t_lst **astack, t_lst **bstack, int *true_tab, int *temp_tab)
{
	ft_sort_a(astack);
	ft_repush(astack, bstack);
	free(temp_tab);
	free(true_tab);
}

void ft_reinit_data2(t_algo_data *data)
{
	data -> nbr_index_a++;
	data -> nbr_index_b = 0;
}

void ft_newalgo(t_lst **astack, t_lst **bstack)
{
	t_algo_data data;
	t_lst *tmp2;
	t_lst *tmp3;
	int *true_tab;
	int *temp_tab;

	ft_init_bstack_and_tabs(astack, bstack, &true_tab, &temp_tab);
	while (ft_stacksize(*astack) > 3)
	{
		ft_tabs(astack, bstack, true_tab, temp_tab);
		ft_reinit_data(&data);
		tmp2 = *bstack;
		tmp3 = *astack;
		while(*astack)
		{
			data.number = (*astack) -> data;
			ft_decision_bstack(bstack, true_tab, temp_tab, &data);
			*astack = (*astack) -> next;
			*bstack = tmp2;
			ft_reinit_data2(&data);
		}
		*astack = tmp3;	
		ft_execute(astack, bstack, true_tab);
	}
	ft_finish(astack, bstack, true_tab, temp_tab);
}











