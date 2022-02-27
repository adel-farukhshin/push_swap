
#include "push_swap.h"
#include "ft_printf.h"

int	check_dup_l(t_stack *l)
{
	t_stack	*cur;
	t_stack	*next;

	if (!l->next)
		return (0);
	cur = l;
	next = l->next;
	while (cur->next)
	{
		while (next)
		{
			if (cur->data == next->data)
				return (1);
			next = next->next;
		}
		cur = cur->next;
		next = cur->next;
	}
	return (0);
}