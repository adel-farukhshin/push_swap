/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:37 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:04:39 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

void	fill_b(t_stack **a, t_stack **b, int argc)
{
	int	min;
	int	max;
	int	i;

	i = 1;
	find_extr((*a), &min, &max);
	printf("min: %d; max: %d \n", min, max);
	// printf("b address: %p\n", (*b));
	while (i < argc)
	{
		if ((*a)->data != min && (*a)->data != max)
			p(a, b);
		else if (i + 1 < argc)
			r(a);
		stacks_printf((*a), (*b));
		i++;
	}
	// printf("b address after while: %p\n", (*b));

}

void sort(t_stack *a, t_stack *b, int argc)
{
	
	fill_b(&a, &b, argc);
	// printf("b address after fill_b: %p\n", b);
	printf("after fill b\n");
	stacks_printf(a, b);

	// stacks_printf(a, b);
	
	// s(&a);
	// stack_printf(a);
	// s(&a);
	// stack_printf(a);
	// printf("\n");
	// p(&a, &b);
	// p(&a, &b);
	// stacks_printf(a, b);
	// p(&b, &a);
	// stacks_printf(a, b);
	// r(&a);
	// printf("\n----------\n");
	// stack_printf(a);
	// rr(&a);
	// printf("\n----------\n");
	// stack_printf(a);

}
