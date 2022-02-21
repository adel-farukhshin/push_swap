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

void sort(t_stack *a, t_stack *b, int argc)
{
	int	min;
	int	max;
	int	i;
	// t_stack *t_a;
	// t_stack *t_b;

	i = 1;
	find_extr(a, &min, &max);
	printf("min: %d; max: %d \n", min, max);
	// t_a = a;
	// t_b = b;
	while (i < argc)
	{
		


		// if ((a->data == min || a->data == max) && i + 1 < argc)
		// 	r(&a);
		// else
		// 	p(&a, &b);

		if (a->data != min && a->data != max)
			p(&a, &b);
		else if (i + 1 < argc)
			r(&a);
	
			

		// t_a = t_a->next;
		stacks_printf(a, b);
		i++;
		// a = a->next;
	}
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
