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
		while(stacks->b)
		{	
			score(stacks);
			// if (q < 2)
			// {
			// 		stacks_printf(stacks->a, stacks->b);
			// 	ascore_printf(stacks->b);
			// 	bscore_printf(stacks->b);
			// }	
			// q++;
			perform(stacks);
			pa(stacks);
		}
	}
	// stacks_printf(stacks->a, stacks->b);
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