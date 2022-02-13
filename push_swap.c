

#include "push_swap.h"


#include <stdio.h>





int	main (int argc, char **argv)
{
	int	i;

	i = check(argc, argv);
	printf("check out %d\n", i);
	if (i == -1)
		return (-1);
	stack_init(argc, argv);
}