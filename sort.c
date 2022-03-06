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

void	sort(t_stacks *stacks, t_arr *array)
{
	if (stacks->la == 5)
		sort_five(stacks, array);
	else
	{
		fill_b(stacks, array);
		while (stacks->b)
		{	
			score(stacks);
			perform(stacks);
			pa(stacks);
		}
	}
}

static int	find_min(t_stack *tmp)
{
	int	pos;
	int	tpos;
	int	min;

	pos = 0;
	tpos = 0;
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
	return (tpos);
}

void	f_sort(t_stacks *stacks)
{
	int	pos;

	pos = find_min(stacks->a);
	if (pos > stacks->la / 2)
		pos = -(stacks->la - pos);
	while (pos > 0)
	{
		ra(stacks);
		pos--;
	}
	while (pos < 0)
	{
		rra(stacks);
		pos++;
	}
}
