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

void	sa(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
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
		stacks->la--;
		stacks->lb++;
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
		stacks->lb--;
		stacks->la++;
		ft_printf("pa\n");
	}
}

void	p(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = (*src)->next;
		lstadd_front(dst, (*src));
		*src = tmp;
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

void	r(t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	lstadd_back(src, tmp);
}

void	rra(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = stacks->a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	lstadd_front(&(*stacks).a, tmp);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = stacks->b;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	lstadd_front(&(*stacks).b, tmp);
	ft_printf("rrb\n");
}

void	rr(t_stack **src)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *src;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	lstadd_front(src, tmp);
}
