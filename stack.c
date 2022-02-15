

#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_init(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		i;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		b = lstnew(ft_atoi(argv[i]));
		lstadd_back(&a, b);
		i++;
	}
	return (a);
}