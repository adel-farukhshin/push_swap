

#include "push_swap.h"


#include <stdio.h>





int	main (int argc, char **argv)
{
	int		i;
	t_stack	*a;

	i = check(argc, argv);
	printf("check out %d\n", i);
	a = stack_init(argc, argv);
	stack_printf(a);
	i = is_final(a);
	printf("is final: %d\n", i);
}