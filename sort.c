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

void	fill_b(t_stacks *stacks)
{
	int	min;
	int	max;
	// int	i;

	// i = 0;
	find_extr(stacks->a, &min, &max);
	printf("min: %d; max: %d \n", min, max);
	// printf("b address: %p\n", (*b));
	printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	stacks_printf(stacks->a, stacks->b);

	while (stacks->la != 2)
	{
		if ((stacks->a)->data != min && (stacks->a)->data != max)
		{
			pb(stacks);
			printf("pb\n");
		}
		else //if (i + 1 < stacks->la)
		{
			r(&(*stacks).a);
			printf("ra\n");
		}
		stacks_printf(stacks->a, stacks->b);
		// i++;
		
	}
	
	printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	// printf("b address after while: %p\n", (*b));

}

void	score(t_stack *b, int lb)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (pos > lb / 2)
			b->bscore = lb - pos;
		else
			b->bscore = pos;
			
		printf("%d ", b->bscore);
		pos++;
		b = b->next;
	}
	
}

void sort(t_stacks *stacks)
{
	fill_b(stacks);
	// fill_b(&(*stacks).a, &(*stacks).b, stacks->la);

	// printf("b address after fill_b: %p\n", b);
	printf("after fill b\n");
	stacks_printf(stacks->a, stacks->b);
	score(stacks->b, stacks->lb);
	// stacks_printf(stacks->a, stacks->b);
	printf("b: ");
	bscore_printf(stacks->b);
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
