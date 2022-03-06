/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:03:41 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:03:42 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_final(t_stack *a)
{
	t_stack	*temp;

	while (a->next)
	{
		temp = a;
		a = a->next;
		if (temp->data > a->data)
			return (0);
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	int		i;
	t_stack	*temp;
	t_stack	*head;

	i = 0;
	head = a;
	while (a->next)
	{
		temp = a;
		a = a->next;
		if (temp->data > a->data)
			i++;
	}
	if (!i || (i == 1 && a->data < head->data))
		return (1);
	else
		return (0);
}
