
#include "push_swap.h"

int	is_final(t_stack *a)
{
	t_stack	*temp;

	while (a->next)
	{
		temp = a;
		a = a->next;
		if (temp->data > a->data)
			return (0);
	}
	return (1);
}