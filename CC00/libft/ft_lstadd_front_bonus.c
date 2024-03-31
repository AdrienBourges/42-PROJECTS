#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst; 
	*lst = new; 
}


// intialement lst pointe sur le premier noeud
	// on a un nouveau noeud "t_list *new" qu'on veut ajouter au debut de la liste chainee
// on fait d'abord pointer le pointeur "next" du noeud new sur le debut de la liste (*lst donc)
	//on actualise ensuite *lst pour que ca pointe sur le nouveau noeud
