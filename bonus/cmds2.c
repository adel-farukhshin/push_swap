/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:52:49 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/06 13:52:50 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdio.h>

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
}
