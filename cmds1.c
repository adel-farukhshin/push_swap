
#include "push_swap.h"

void	s(t_stack **a)
{
	t_stack	*tmp;
	// t_stack	*tmp2;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	


}