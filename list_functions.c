/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:03 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:04:04 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include "push_swap.h"

t_stack  *lstnew(int data)
{
    t_stack  *a;

    a = malloc(sizeof(t_stack));
    a->data = data;
	a->next = NULL;
    return (a);
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *(lst);
	*lst = new;
}

int	lstsize(t_stack *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_stack	*lstlast(t_stack *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
