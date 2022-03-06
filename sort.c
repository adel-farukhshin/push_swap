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
#include "ft_printf.h"



void sort(t_stacks *stacks, t_arr *array)
{
	// int q = 0;
	if (stacks->la == 5)
		sort_five(stacks, array);

	else
	{
		fill_b(stacks, array);
		// stacks_printf(stacks->a, stacks->b);
		// fill_b(&(*stacks).a, &(*stacks).b, stacks->la);
		while(stacks->b)
		{

			
			// ft_printf("b address after fill_b: %p\n", b);
			// ft_printf("after fill b\n");
			
			
			
			score(stacks);
			// if (q < 2)
			// {
			// 		stacks_printf(stacks->a, stacks->b);
			// 	ascore_printf(stacks->b);
			// 	bscore_printf(stacks->b);
			// }
			
			// q++;
			// ft_printf("after score\n");
		
			// pos_printf(stacks->a);
			// pos_printf(stacks->b);

			perform(stacks);
			pa(stacks);
		}
	}
	// pa(stacks);
	
	// stacks_printf(stacks->a, stacks->b);
	
	// stacks_printf(stacks->a, stacks->b);
	// ft_printf("b: ");
	// bscore_printf(stacks->b);
	// stacks_printf(a, b);
	
	// s(&a);
	// stack_printf(a);
	// s(&a);
	// stack_printf(a);
	// ft_printf("\n");
	// p(&a, &b);
	// p(&a, &b);
	// stacks_printf(a, b);
	// p(&b, &a);
	// stacks_printf(a, b);
	// r(&a);
	// ft_printf("\n----------\n");
	// stack_printf(a);
	// rr(&a);
	// ft_printf("\n----------\n");
	// stack_printf(a);

}

void f_sort(t_stacks *stacks)
{
	int	pos;
	int	tpos;
	int	min;
	t_stack *tmp;

	pos = 0;
	tpos = 0;
	tmp = stacks->a;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			tpos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	pos = tpos;
	// ft_printf("pos %d\n", pos);
	if (pos > stacks->la / 2)
		pos = -(stacks->la - pos);
	// ft_printf("pos %d\n", pos);
	while (pos > 0)
	{
		ra(stacks);
		pos--;
	}
	// ft_printf("after -- pos %d\n", pos);
	while (pos < 0)
	{
		rra(stacks);
		pos++;
	}
	// ft_printf("after ++ pos %d\n", pos);
	// stacks_printf(stacks->a, stacks->b);

}