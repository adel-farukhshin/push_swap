
#include <stdio.h>
#include "push_swap.h"

void stack_printf(t_stack *a)
{
	while (a)
	{
		printf("%d ", a->data);
		a = a->next;
	}
}