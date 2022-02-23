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


#include "ft_printf.h"
#include "push_swap.h"

void	stacks_printf(t_stack *a, t_stack *b)
{
	ft_printf("\n-----------\n");
	ft_printf("a: ");
	stack_printf(a);
	ft_printf("\n");
	ft_printf("b: ");
	stack_printf(b);
	ft_printf("\n-----------\n");
}

void	stack_printf(t_stack *a)
{
	while (a)
	{
		ft_printf("%d ", a->data);
		a = a->next;
	}
}

void	bscore_printf(t_stack *a)
{
	ft_printf("b score: ");
	while (a)
	{
		ft_printf("%d ", a->bscore);
		a = a->next;
	}
	ft_printf("\n");
}

void	ascore_printf(t_stack *a)
{
	ft_printf("a score: ");
	while (a)
	{
		ft_printf("%d ", a->ascore);
		a = a->next;
	}
	ft_printf("\n");
}

void	pos_printf(t_stack *a)
{
	ft_printf("pos : ");
	while (a)
	{
		ft_printf("%d ", a->ps);
		a = a->next;
	}
	ft_printf("\n");
}