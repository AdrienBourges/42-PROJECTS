/*  #include "ft_pushswap.h"

double ft_average(t_lst *head)
{
	t_lst *current;
	double total;
	double i;
	double average;

	i = 0;
	total = 0;
	average = 0;
	current = head;
	while (current)
	{
		total += current -> data;
		i++;
		current = current -> next;
	}
	if (i == 0)
		return 0;
	average = total / i;
	return (average);
}

void ft_divide (int argc, t_lst **head_a, t_lst **head_b)
{
	int i;
	int average;

	average = ft_average(*head_a);
	i = argc - 1;
	while (i > 0)
	{
		if ((*head_a) -> data < average)
			ft_push_b(head_a, head_b);
		else
			ft_rotate(head_a);
		i--;
	}
}

int ft_is_ordered(t_lst **head_a, t_lst **head_b)
{
	t_lst *current;

	current = *head_a;
	while (current -> next)
	{
		if (current -> data > current -> next -> data)
			return (0);
		current = current -> next;
	}
	current = *head_b;
	while (current -> next)
	{
		if (current -> data < current -> next -> data)
			return (0);
		current = current -> next;
	}
	return (1);
}

 int ft_last(t_lst **head)
{
	t_lst *current;

	current = *head;
	while (current -> next)
		current = current -> next;
	return (current -> data);
}

int ft_is_pivot_rotate(t_lst **head_a, t_lst **head_b)
{
	double average_a;
	double average_b;
	double average_value_a;
	double average_value_b;

	average_a = ft_average(*head_a);
	average_b = ft_average(*head_b);
	average_value_a = ((double)(*head_a) -> data + ft_last(head_a)) / 2; 
	average_value_b = ((double)(*head_b) -> data + ft_last(head_b)) / 2; 
	if (average_value_a >= average_a && average_value_b <= average_b)
		return (1);
	return (0);
}

int ft_is_pivot_rrotate(t_lst **head_a, t_lst **head_b)
{
	double average_a;
	double average_b;
	double average_value_a;
	double average_value_b;

	average_a = ft_average(*head_a);
	average_b = ft_average(*head_b);
	average_value_a = ((double)(*head_a) -> data + ft_last(head_a)) / 2; 
	average_value_b = ((double)(*head_b) -> data + ft_last(head_b)) / 2; 
	if (average_value_a <= average_a && average_value_b >= average_b)
		return (1);
	return (0);
}


int ft_is_double(t_lst **head_a, t_lst **head_b, int *op_index)
{	
	if ((*head_a) -> data >= (*head_a) -> next -> data && ((*head_b) -> data <= (*head_b) -> next -> data))
		return (1);
	if ((*head_a) -> data >= ft_last(head_a) && (*head_b)-> data <= ft_last(head_b) && ft_is_pivot_rotate(head_a, head_b) && op_index[0] != 2 && op_index[1] != 2) //la fct is_pivot_ok va check si il y a concordance pour utiliser rrotate ou rrrotate
		return (1);
	if ((*head_a) -> data >= ft_last(head_a) && (*head_b)-> data <= ft_last(head_b)  && ft_is_pivot_rrotate(head_a, head_b) && op_index[0] != 1 && op_index[1] != 1)
		return(1);
	return (0);
}

int ft_pivot_rrotate(t_lst **head_a, t_lst **head_b)
{
	double average_a;
	double average_b;
	double average_value_a;
	double average_value_b;

	average_a = ft_average(*head_a);
	average_b = ft_average(*head_b);
	average_value_a = ((double)(*head_a) -> data + ft_last(head_a)) / 2; 
	average_value_b = ((double)(*head_b) -> data + ft_last(head_b)) / 2; 
	if (average_value_a >= average_a && average_value_b <= average_b)
		return (1);
	return (0);
}

int ft_pivot_rrrotate(t_lst **head_a, t_lst **head_b)
{
	double average_a;
	double average_b;
	double average_value_a;
	double average_value_b;

	average_a = ft_average(*head_a);
	average_b = ft_average(*head_b);
	average_value_a = ((double)(*head_a) -> data + ft_last(head_a)) / 2; 
	average_value_b = ((double)(*head_b) -> data + ft_last(head_b)) / 2; 
	if (average_value_a <= average_a && average_value_b >= average_b)
		return (1);
	return (0);
}

void ft_double (t_lst **head_a, t_lst **head_b, int *op_index)
{//en optimisation: a voir si on peut elargir un peu le scope des ft_double sans que ca soit efficient du point de vu de l'average pour les 2 necessairement ?

	if ((*head_a) -> data >= (*head_a) -> next -> data && ((*head_b) -> data <= (*head_b) -> next -> data) && (*head_a) -> data >= ft_last(head_a) && (*head_b)-> data <= ft_last(head_b))
	{

	if ((*head_a) -> data >= (*head_a) -> next -> data && ((*head_b) -> data <= (*head_b) -> next -> data))
	{
		ft_sswap(*head_a, *head_b);
		op_index[0] = 0;
		op_index[1] = 0;
	}
	else if ((*head_a) -> data >= ft_last(head_a) && (*head_b)-> data <= ft_last(head_b) && ft_pivot_rrotate(head_a, head_b))
	{
		ft_rrotate(head_a, head_b);
		op_index[0] = 1;
		op_index[1] = 1;
	}
	else if ((*head_a) -> data >= ft_last(head_a) && (*head_b)-> data <= ft_last(head_b) && ft_pivot_rrrotate(head_a, head_b))
	{
		ft_rreverse_rotate(head_a, head_b);
		op_index[0] = 2;
		op_index[1] = 2;
	}
}

int ft_pivot_rotate(t_lst **head)
{
	double average;
	double average_value;

	average = ft_average(*head);
	average_value = ((double)(*head) -> data + ft_last(head)) / 2; 
	if (average_value >= average)
		return (1);
	return (0);
}

int ft_pivot_reverse_rotate(t_lst **head)
{
	double average;
	double average_value;

	average = ft_average(*head);
	average_value = ((double)(*head) -> data + ft_last(head)) / 2; 
	if (average_value <= average)
		return (1);
	return (0);
}


void ft_solo(t_lst **head_a, t_lst **head_b, int *op_index)
{// check sur swap et les rotate a faire afin de prendre la meilleure decision, a faire aussi dans ft_double
 
	if ((*head_a) -> data > (*head_a) -> next -> data && (*head_a) -> data >= ft_last(head_a))
	{
		if ((*head_a) -> data - (*head_a) -> next -> data < (*head_a) -> data - ft_last(head_a))
		{
			ft_swap(*head_a);
			op_index[0] = 0;
			return ;
		}
		else if (ft_pivot_rotate(head_a))
		{
			ft_rotate(head_a);
			op_index[0] = 1;
			return ;
		}
		else if (ft_pivot_reverse_rotate(head_a))
		{
			ft_reverse_rotate(head_a);
			op_index[0] = 2;
			return ;
		}
	}
	if ((*head_b) -> data < (*head_b) -> next -> data && (*head_b) -> data <= ft_last(head_b))
	{
		if ((*head_b) -> data - (*head_b) -> next -> data < (*head_b) -> data - ft_last(head_b))
		{
			ft_swap(*head_b);
			op_index[1] = 0;
			return ;
		}
		else if (ft_pivot_rotate(head_b))
		{
			ft_reverse_rotate(head_b);
			op_index[1] = 2;
			return ;
		}
		else if (ft_pivot_reverse_rotate(head_b))
		{
			ft_rotate(head_b);
			op_index[0] = 1;
			return ;
		}
	}

	if ((*head_a) -> data > (*head_a) -> next -> data )
	{
		ft_swap(*head_a);
		op_index[0] = 0;
		return ;
	}
	if ((*head_b) -> data < (*head_b) -> next -> data)
	{
		ft_swap(*head_b);
		op_index[1] = 0;
		return ;
	}
	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_rotate(head_a))
	{
		ft_rotate(head_a);
		op_index[0] = 1;
		return ;
	}

	if ((*head_b) -> data <= ft_last(head_b) && ft_pivot_reverse_rotate(head_b))
	{
		ft_rotate(head_b);
		op_index[1] = 1;
		return ;
	}

	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_reverse_rotate(head_a))
	{
		ft_reverse_rotate(head_a);
		op_index[0] = 2;
		return ;
	}
	if ((*head_b) -> data <= ft_last(head_b)  && ft_pivot_rotate(head_b))
	{
		ft_reverse_rotate(head_b);
		op_index[1] = 2;
		return ;
	}
}	

int ft_is_solo(t_lst **head_a, t_lst **head_b, int *op_index)
{
	if ((*head_a) -> data > (*head_a) -> next -> data)
	   return (1);
	if ((*head_b) -> data < (*head_b) -> next -> data)
		return (1);
	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_rotate(head_a) && op_index[0] != 2)
		return (1);
	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_reverse_rotate(head_a) && op_index[0] != 1)
		return (1);
	if ((*head_b) -> data <= ft_last(head_b) && ft_pivot_rotate(head_b) && op_index[1] != 1)
		return(1);
	if ((*head_b) -> data <= ft_last(head_b) && ft_pivot_reverse_rotate(head_b) && op_index[1] != 2)
		return (1);
	return (0);
}	

int ft_is_ordered_a(t_lst **head_a)
{
	t_lst *current;

	current = *head_a;
	while (current -> next)
	{
		if (current -> data > current -> next -> data)
			return (0);
		current = current -> next;
	}
	return (1);
}

int ft_is_ordered_b(t_lst **head_b)
{
	t_lst *current;

	current = *head_b;
	while (current -> next)
	{
		if (current -> data < current -> next -> data)
			return (0);
		current = current -> next;
	}
	return (1);
}

int ft_is_solo_a(t_lst **head_a, int *op_index)
{
	if ((*head_a) -> data > (*head_a) -> next -> data)
	   return (1);
	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_rotate(head_a) && op_index[0] != 2)
		return (1);
	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_reverse_rotate(head_a) && op_index[0] != 1)
		return (1);
	return (0);
}
int ft_is_solo_b(t_lst **head_b, int *op_index)
{
	if ((*head_b) -> data < (*head_b) -> next -> data)
		return (1);
	if ((*head_b) -> data <= ft_last(head_b) && ft_pivot_rotate(head_b) && op_index[1] != 1)
		return(1);
	if ((*head_b) -> data <= ft_last(head_b) && ft_pivot_reverse_rotate(head_b) && op_index[1] != 2)
		return (1);
	return (0);
}
void ft_solo_b(t_lst **head_b, int *op_index)
{
	if ((*head_b) -> data < (*head_b) -> next -> data && (*head_b) -> data <= ft_last(head_b))
	{
		if ((*head_b) -> data - (*head_b) -> next -> data < (*head_b) -> data - ft_last(head_b))
		{
			ft_swap(*head_b);
			op_index[1] = 0;
			return ;
		}
		else if (ft_pivot_rotate(head_b))
		{
			ft_reverse_rotate(head_b);
			op_index[1] = 2;
			return ;
		}
		else if (ft_pivot_reverse_rotate(head_b))
		{
			ft_rotate(head_b);
			op_index[0] = 1;
			return ;
		}
	}
	if ((*head_b) -> data < (*head_b) -> next -> data)
	{
		ft_swap(*head_b);
		op_index[1] = 0;
		return ;
	}

	if ((*head_b) -> data <= ft_last(head_b) && ft_pivot_reverse_rotate(head_b))
	{
		ft_rotate(head_b);
		op_index[1] = 1;
		return ;
	}
	if ((*head_b) -> data <= ft_last(head_b)  && ft_pivot_rotate(head_b))
	{
		ft_reverse_rotate(head_b);
		op_index[1] = 2;
		return ;
	}
}


void ft_solo_a(t_lst **head_a, int *op_index)
{
	if ((*head_a) -> data > (*head_a) -> next -> data && (*head_a) -> data >= ft_last(head_a))
	{
		if ((*head_a) -> data - (*head_a) -> next -> data < (*head_a) -> data - ft_last(head_a))
		{
			ft_swap(*head_a);
			op_index[0] = 0;
			return ;
		}
		else if (ft_pivot_rotate(head_a))
		{
			ft_rotate(head_a);
			op_index[0] = 1;
			return ;
		}
		else if (ft_pivot_reverse_rotate(head_a))
		{
			ft_reverse_rotate(head_a);
			op_index[0] = 2;
			return ;
		}
	}
	if ((*head_a) -> data > (*head_a) -> next -> data )
	{
		ft_swap(*head_a);
		op_index[0] = 0;
		return ;
	}
		if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_rotate(head_a))
	{
		ft_rotate(head_a);
		op_index[0] = 1;
		return ;
	}	
	if ((*head_a) -> data >= ft_last(head_a) && ft_pivot_reverse_rotate(head_a))
	{
		ft_reverse_rotate(head_a);
		op_index[0] = 2;
		return ;
	}
}


void ft_stuck(t_lst **head_a, t_lst **head_b, int *op_index)
{
	int push_counter;

	push_counter = 0;
	if (!ft_is_ordered_a(head_a))
	{
		while (!ft_is_solo_a(head_a, op_index))
		{
			ft_push_b(head_a, head_b);
			push_counter++;
		}
		ft_solo_a(head_a, op_index);
		// ici on pourrait mettre une boucle d'actions solos ? a voir en test si ca peut etre + efficace que de tout repasser directement quand une operation est effectuee
		while (push_counter > 0)
		{
			ft_push_a(head_a, head_b);
			push_counter--;
		}
	}
	else if (!ft_is_ordered_b(head_b))
	{
		while (!ft_is_solo_b(head_b, op_index))
		{
			ft_push_a(head_a, head_b);
			push_counter++;
		}
		ft_solo_b(head_b, op_index);
		while (push_counter > 0)
		{
			ft_push_b(head_a, head_b);
			push_counter--;
		}
	}
}

void ft_sort(int argc, t_lst **head_a, t_lst **head_b)
{
	int op_index[2];
	   
	op_index[0] = 0;
	op_index[1] = 0;
	int counter = 0;
	int double_counter = 0;
	int solo_counter = 0;
	int stuck_counter = 0;
	
	while (!ft_is_ordered (head_a, head_b))
	{
		if (ft_is_double(head_a, head_b, op_index))
		{
			ft_double(head_a, head_b, op_index);
			double_counter++;
		}
		else if (ft_is_solo(head_a, head_b, op_index))
		{
			ft_solo(head_a, head_b, op_index);
			solo_counter++;
		}
		else 
		{
			ft_stuck(head_a, head_b, op_index);
			stuck_counter++;
		}
		counter++;
		printf("astack: ");
		print_stack(*head_a);
		printf("bstack: ");
		print_stack(*head_b);
	}
	printf("nombre d'operations  : %d\n",counter);

	printf("nombre d'operations doubles  : %d\n",double_counter);
	printf("nombre d'operations solos : %d\n",solo_counter);
	printf("nombre d'operations stuck : %d\n",stuck_counter);
}

// on doit maintenant implementer le push pour debloquer, je crois que cest plus efficace que le random rotate que je fais, ca implique de refaire la fct ft_stuck

// Plus simple de manipuler un tableau d'entier pour keep track des moves peut etre ? on peut comme ca envoyer le dernier double move et les derniers move simples. meme pas besoin davoir un op_index en fait si on stock dans un tableau d'entier les derniers move de a et b.

// A IMPLEMENTER NEXT : ON doit keep track du dernier mouvement de a et de b separement, sinon une op solo se passe sur b et on oublie ce qu'on a fait sur a 2 coups avants
// pour le moment dans ft_stuck on fait un double mouvement si les 2 stacks ne sont pas organisees, or on ne souhaite pas forcement faire ca et plutot faire des mouvements indiv

//A IMPLEMENTER NEXT: Je me retrouve stuck dans des loops systematiquement, on peut essayer de garder une trace du dernier mouvement afin de ne pas reproduire son oppose sur le mouvement d'apres. Il faut simplement foutre des int un peu partout afin de le rajouter en condition. J'espere juste ne pas me retrouver stuck sans aucun mouvement possible.

//IDEE A IMPLENTEE NEXT: on doit trier chaque stack en prenant en compte la valeur pivot de chaque stack. Ca va nous permettre de trier b dans le bon ordre car on va pouvoir utiliser les double mouvements, on se servira de rrotate et rrrotate si les mouvements ont du sens de maniere generale par rapport aux valeurs manipulees et leur difference avec la valeur pivot de chaque stack. Pour ft stuck et ft solo on agira pareil en prenant bien en compte la valeur pivot par rapport aux valeurs manipulees.


//Idee pour plus tard : on calcule dabord la moyenne de la serie. on compte le nombre de valeurs au dessus et en dessous. si c'est pas du tout egal, on recommence en modifiant la valeur par rapport au % de valeurs au dessus et en dessous. s'il y a 1 valeur au dessus et 499 en dessous on va vouloir bcp modifier cette moyenne, donc  

   int ft_median(t_lst *head)
   {
   int average;
   t_lst *current;
   int sup;
   int inf;

   average = ft_average(head);
   current = head;
   sup = 0;
   inf = 0;
   while (current -> next)
   {
   if (current -> data > average)
   sup++;
   if (current-> data < average)
   inf++;
   current = current -> next;
   }
   while (sup != inf)
   {
   if (sup > inf)
   average++;
   else if (inf > sup)
   average--;
   sup = 0;
   inf = 0;
   current = head;
   while (current -> next)
   {
   if (current -> data > average)
   sup++;
   if (current-> data < average)
   inf++;
   current = current -> next;
   }
   }
   return (average);
   }*/


