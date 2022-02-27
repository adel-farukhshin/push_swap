/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:34:05 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/27 15:34:07 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	mod(int q)
{
	if (q < 0)
		return (q * (-1));
	else
		return (q);
}


static t_stack *sum(t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while(b)
	{
		if ((mod(tmp->ascore) + mod(tmp->bscore)) >
			(mod(b->ascore) + mod(b->bscore)))
			tmp = b;
		b = b->next;
	}
	return (tmp);
}

void perform(t_stacks *stacks)
{
	t_stack *cur;

	cur = sum(stacks->b);
	while (cur->bscore > 0)
	{
		rb(stacks);
		cur->bscore--;
	}
	while (cur->bscore < 0)
	{
		rrb(stacks);
		cur->bscore++;
	}

	while (cur->ascore > 0)
	{
		ra(stacks);
		// ft_printf("perform \n");
		cur->ascore--;
	}
	while (cur->ascore < 0)
	{
		rra(stacks);
		cur->ascore++;
	}
	// rb(stacks);
	// ra(stacks);
	// stacks_printf(stacks->a, stacks->b);
	// rra(stacks);
	// rrb(stacks);
	// stacks_printf(stacks->a, stacks->b);
	// printf("%d ", cur->data);
	
}
