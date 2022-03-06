/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:44:51 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/27 16:44:52 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	ismaxinstack(t_stacks *stacks, int val)
{
	t_stack	*tmp;

	tmp = stacks->a;
	while (tmp)
	{
		if (tmp->data > val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_five(t_stacks *stacks, t_arr *array)
{
	int	min;
	int	med;
	int	max;

	find_ms(array, &min, &med, &max);
	while (stacks->la != 3)
		pb(stacks);
	sort_tripple(stacks);
	if (!is_final(stacks->b))
		rb(stacks);
	while (stacks->b)
	{
		if ((stacks->b)->data < (stacks->a)->data)
			pa(stacks);
		else if (ismaxinstack(stacks,
				(stacks->b)->data) && (stacks->a)->data == min)
			pa(stacks);
		ra(stacks);
	}
}
