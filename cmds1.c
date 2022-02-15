
#include "push_swap.h"
#include <stdlib.h>

void	s(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	p(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = (*src)->next;
		lstadd_front(dst, (*src));
		*src = tmp;
	}
}

void	r(t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	lstadd_back(src, tmp);
}