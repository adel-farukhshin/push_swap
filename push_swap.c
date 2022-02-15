

#include "push_swap.h"


#include <stdio.h>





int	main (int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = check(argc, argv);
	printf("check out %d\n", i);
	a = stack_init(argc, argv);
	b = NULL;
	stack_printf(a);
	i = is_sorted(a);
	printf("is sorted: %d\n", i);
	if (!i)
	{
		sort(a, b);
	}
	i = is_final(a);
	printf("is final: %d\n", i);
}