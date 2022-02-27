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

int	ismaxinstack(t_stacks *stacks, int max)
// int	ismaxinstack(t_stacks *stacks, int val)
{
	t_stack	*tmp;

	tmp = stacks->b;
	while (tmp)
	{
		if (tmp->data == max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort_five(t_stacks *stacks, int *arr)
{
	int	min;
	int	med;
	int	max;


	// ft_printf("i %d %d \n", stacks->la, arr[0]);

	stacks_printf(stacks->a, stacks->b);
	find_ms(arr, &min, &med, &max);
	while (stacks->la != 3)
		pb(stacks);
	sort_tripple(stacks);
	stacks_printf(stacks->a, stacks->b);
	if (!is_final(stacks->b))
		rb(stacks);
	stacks_printf(stacks->a, stacks->b);
	while (stacks->b)
	{
		if ((stacks->b)->data < (stacks->a)->data)
			pa(stacks);
		else if (ismaxinstack(stacks, max) && (stacks->a)->data == min)
			pa(stacks);
		ra(stacks);

		stacks_printf(stacks->a, stacks->b);
	}
}
