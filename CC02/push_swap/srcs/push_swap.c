#include "../includes/ft_pushswap.h"
#include <stdio.h>

void ft_free(t_lst *stack)
{
	t_lst *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack -> next;
		free(tmp);
	}
}

void ft_exit(t_lst *stack, char **tab)
{
	int i;

	i = 0;
	ft_free(stack);
	write(2, "Error\n", 6);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	exit(1);
}

int 	ft_amoi(char *str, t_lst *stack, char **tab)
{
	long long result;
	int i;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	if (!str[i])
		ft_exit(stack, tab); 
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit(stack, tab);
		result = (result * 10) + (str[i] - 48);
		if (result * sign > 2147483647 || result * sign < -2147483648)
			ft_exit(stack, tab);
		i++;
	}
	return ((int) result * sign);
}

void print_stack(t_lst *head) 
{
    while (head != NULL) 
	{
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main (int argc, char **argv)
{
	t_lst *astack;
	t_lst *bstack;
	char **tab;
	int i;

	i = 0;
	bstack = NULL;
	if (argc <= 1)
		exit(1);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab)
			ft_exit(0,0);
	}
	else
	{
		tab = malloc(argc * sizeof(char *));
		if (!tab)
			ft_exit(0,0); //que faire dans ce cas ?
		while (argv[i + 1])
		{
			tab[i] = ft_strdup(argv[i + 1]);
			if (!tab[i])
				ft_exit(0,tab);
			// si le malloc du ft_strdup fail on est cense sortir je pense
			i++;
		}
		tab[i] = NULL;
	}
	//if (!tab[0]) //pas sur de l'utilite de ce machin
	//	ft_exit(0, tab);
	astack = ft_init(tab);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	//if (!astack)
	//	return 0;
	ft_newalgo(&astack, &bstack);
	printf("astack: ");
	print_stack(astack);
	printf("bstack: ");
	print_stack(bstack);
	//printf("nombre de mouvements : %d", result);
	i = 0;
	ft_free(astack);
	ft_free(bstack);
}
