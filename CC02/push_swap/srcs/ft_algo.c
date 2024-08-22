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


/*void ft_execute(t_lst **astack, t_lst **bstack, int *tab)
{

	int rotate_a;
	int r_rotate_a;
	int rotate_b;
	int r_rotate_b;

	rotate_a = 0;
	r_rotate_a = 0;
	rotate_b = 0;
	r_rotate_b = 0;
	//ici on compte le nombre de move pour mettre le nombre desire au top de la stack A;
	if (tab[2] > (tab[0] / 2))
		r_rotate_a = tab[0] - tab[2];
	else if (tab[2] <= (tab[0] / 2))
		rotate_a = tab[2];
	else
	{
		// les 2 rotations sont equivalentes en nombre de coup dans le cas d'une stack size paire sur le n/2 +1 element.
	}

	if (tab[3] > (tab[1] / 2))
		r_rotate_b = tab[1] - tab[3];
	else if(tab[3] <= (tab[1] / 2))
		rotate_b = tab[3];
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

void ft_repush(t_lst **astack, t_lst **bstack)
{
	// on doit dabord organiser bstack en prenant la pos du max, la size de la stack pour ajuster le nombre de rotate ou de r_rotate
	// puis on repush en checkant a quel moment ou doit r_rotate pour repasser le dernier element de astack au bon endroit

	int size_b;
	int max_b;
	int max_a;
	int min_a;
	int pos_max_b;
	int mid_a;
	int tab[3];
	int i;

	if (!bstack || !*bstack)
		return ;
	size_b = ft_stacksize(*bstack);
	max_b = ft_max(*bstack);
	max_a = ft_max(*astack);
	min_a = ft_min(*astack);
	pos_max_b = ft_findpos(*bstack, max_b);
	mid_a = (*astack) -> next -> data;
	tab[0] = max_a;
	tab[1] = mid_a;
	tab[2] = min_a;

	if (pos_max_b <= size_b / 2)
	{
		while (pos_max_b > 0)
		{
			ft_rotate(bstack, 'b');
			pos_max_b--;
		}
	}
	else
	{
		while (pos_max_b < size_b)
		{
			ft_reverse_rotate(bstack, 'b');
			pos_max_b++;
		}
	}
	i = 0;
	while(i < 3)
	{
		while (bstack && (*bstack) && (*bstack)-> data > tab[i])
		{
			ft_push_a(astack, bstack);
		}
		i++;
		ft_reverse_rotate(astack,'a');
	}
	while (*bstack)
	{
		ft_push_a(astack, bstack);
	}
}


void ft_newalgo(t_lst **astack, t_lst **bstack)
{
	// je crois qu'il y a un probleme sur les nbr_index qui sont mal reset, update: en princpe c'est fix
	int move_count;
	int nbr_index_a;
	int nbr_index_b;
	int size_a;
	int size_b;
	int number;
	t_lst *tmp;
	t_lst *tmp2;
	t_lst *tmp3;
	int *true_tab;
	int *temp_tab;
	int max_b;
	int pos_max_b;
	int temp_counter;
	int first_b;
	int last_b;
//	int result;

	//result = 0;
	true_tab = malloc(sizeof(int) * 4); // tableau de la forme: {size_a, size_b, index_a, index_b};
	if (!true_tab)
	{
		ft_exit(*astack, 0);
	}
	temp_tab = malloc(sizeof(int) * 4);
	if (!temp_tab)
	{
		free(true_tab);
		ft_exit(*astack, 0);
		//ft_exit(astack, bstack, true_tab, temp_tab);
	}
	if (ft_stacksize(*astack) > 3 && ft_stacksize(*astack) != 4)
	{
		ft_push_b(astack, bstack);
		ft_push_b(astack, bstack);	
	}
	else if (ft_stacksize(*astack) == 4)
		ft_push_b(astack, bstack);

	while (ft_stacksize(*astack) > 3)
	{
		number = (*astack) -> data;
		nbr_index_a = 0;
		nbr_index_b = 0;
		size_a = ft_stacksize(*astack);
		size_b = ft_stacksize(*bstack);
		true_tab[0] = size_a;
		true_tab[1] = size_b;
		temp_tab[0] = size_a;
		temp_tab[1] = size_b;
		max_b = ft_max(*bstack);
		pos_max_b = ft_findpos(*bstack, max_b);
		tmp2 = *bstack;
		tmp3 = *astack;
		first_b = (*bstack) -> data;
		last_b = ft_last(*bstack);
		move_count = 10000;

		while(*astack)
		{
			while ((*bstack) -> next)
			{
				tmp = (*bstack) -> next;  
				if (number > max_b || number < ft_min(*bstack))
				{
					temp_tab[2] = nbr_index_a;
					temp_tab[3] = pos_max_b;
					temp_counter = ft_move_counter(temp_tab);
					if (move_count > temp_counter)
					{
						move_count = temp_counter;
						true_tab[2] = temp_tab[2];
						true_tab[3] = temp_tab[3];
						// pour opti on doit se stop si on a un nombre de coup optimal(exemple :un seul coup puis 2 coups puis 3 coups..., et a partir de la moitie de la size a on decremente notre indice de coup opti. a implementer plus tard peut etre)
					}
					break;
				}
				else if (number < (*bstack) -> data && number > tmp -> data)
				{
					temp_tab[2] = nbr_index_a;
					temp_tab[3] = nbr_index_b + 1;
					temp_counter = ft_move_counter(temp_tab);
					//true_tab = temp_tab;
					if (move_count > temp_counter)
					{
						move_count = temp_counter;
						true_tab[2] = temp_tab[2];
						true_tab[3] = temp_tab[3];
					}
					break;
					//on rentre la position dans notre double tableau
					//on calcule le nombre de coup avec notre super fonction
					//pour garder en memoire le bon double tableau d'information on peut creer un double tableau temp qu'on modifie a chaque fois. Si ce double tableau bat le tableau en place, on le remplace simplement !
					//a la fin on execute une autre super fonction qui prend en parametre le bon double tableau et effectue les mouvements correspondants
				}
				else if (number >  first_b && number < last_b)
				{
					temp_tab[2] = nbr_index_a;
					temp_tab[3] = 0;
					temp_counter = ft_move_counter(temp_tab);	
					if (move_count > temp_counter)
					{
						move_count = temp_counter;
						true_tab[2] = temp_tab[2];
						true_tab[3] = temp_tab[3];
					}
					break;
				}
				else
				{
					*bstack = (*bstack) -> next;
					nbr_index_b++;
				}
			}
			*astack = (*astack) -> next;
			if (*astack)
				number = (*astack) -> data;
			*bstack = tmp2;
			nbr_index_a++;
			nbr_index_b = 0;
		}
		*astack = tmp3;// bien faire gaffe aux reset de pointeurs sur les debuts de liste a chaque fois	
		//ft_push_b(astack, bstack);
		
		ft_execute(astack, bstack, true_tab);
		//result+= move_count + 1;
	}
	ft_sort_a(astack);
	ft_repush(astack, bstack);
	free(temp_tab);
	free(true_tab);
//	return result;	
}











