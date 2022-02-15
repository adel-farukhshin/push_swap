

#include "push_swap.h"


#include <stdio.h>





int	main (int argc, char **argv)
{
	int		i;
	t_stack	*a;

	i = check(argc, argv);
	printf("check out %d\n", i);
	if (i == -1)
		return (-1);
	a = stack_init(argc, argv);
	stack_printf(a);

}