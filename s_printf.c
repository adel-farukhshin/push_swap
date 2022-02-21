/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:30 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:04:31 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "push_swap.h"

void	stacks_printf(t_stack *a, t_stack *b)
{
	printf("\n-----------\n");
	printf("a: ");
	stack_printf(a);
	printf("\n");
	printf("b: ");
	stack_printf(b);
	printf("\n-----------\n");
}

void	stack_printf(t_stack *a)
{
	while (a)
	{
		printf("%d ", a->data);
		a = a->next;
	}
}

void	bscore_printf(t_stack *a)
{
	printf("b score: ");
	while (a)
	{
		printf("%d ", a->bscore);
		a = a->next;
	}
	printf("\n");
}

void	ascore_printf(t_stack *a)
{
	printf("a score: ");
	while (a)
	{
		printf("%d ", a->ascore);
		a = a->next;
	}
	printf("\n");
}