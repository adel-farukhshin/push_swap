/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:03:52 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:03:54 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdio.h>

void	sa(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->a;
	stacks->a = (stacks->a)->next;
	tmp->next = (stacks->a)->next;
	(stacks->a)->next = tmp;
	ft_printf("sa\n");
}

void	pb(t_stacks *stacks)
{
	t_stack	*tmp;

	if (stacks->a)
	{
		tmp = (stacks->a)->next;
		lstadd_front(&(*stacks).b, stacks->a);
		stacks->a = tmp;
		ft_printf("pb\n");
	}
}

void	pa(t_stacks *stacks)
{
	t_stack	*tmp;

	if (stacks->b)
	{
		tmp = (stacks->b)->next;
		lstadd_front(&(*stacks).a, stacks->b);
		stacks->b = tmp;
		ft_printf("pa\n");
	}
}

void	ra(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->a;
	stacks->a = (stacks->a)->next;
	tmp->next = NULL;
	lstadd_back(&(*stacks).a, tmp);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->b;
	stacks->b = (stacks->b)->next;
	tmp->next = NULL;
	lstadd_back(&(*stacks).b, tmp);
	ft_printf("rb\n");
}
