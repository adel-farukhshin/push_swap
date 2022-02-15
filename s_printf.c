
#include <stdio.h>
#include "push_swap.h"

void	stacks_printf(t_stack *a, t_stack *b)
{
	printf("\n-----------\n");
	printf("a: ");
	stack_printf(a);
	printf("\n");
	printf("b: ");
	stack_printf(b);
	printf("\n-----------\n");
}

void	stack_printf(t_stack *a)
{
	while (a)
	{
		printf("%d ", a->data);
		a = a->next;
	}
}