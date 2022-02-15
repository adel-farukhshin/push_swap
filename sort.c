
#include "push_swap.h"

#include <stdio.h>

void find_extr(t_stack *a, int *min, int *max)
{
	*min = a->data;
	*max = a->data;
	while (a)
	{
		if (a->data > *max)
			*max = a->data;
		if (a->data < *min)
			*min = a->data;
		a = a->next;
	}
}

void sort(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	find_extr(a, &min, &max);
	printf("min: %d; max: %d \n", min, max);
	b = (void *)b;
}