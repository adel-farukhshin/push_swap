/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:16 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:04:17 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"


#include <stdio.h>

#include <stdlib.h>



int	main (int argc, char **argv)
{
	int		i;
	t_stacks	*stacks;
	// t_stack	*a;
	// t_stack	*b;

	i = check(argc, argv);
	printf("check out %d\n", i);
	stacks = malloc(sizeof(t_stacks *));
	stacks->a = stack_init(argc, argv);
	stacks->b = NULL;
	stack_printf(stacks->a);
	i = is_sorted(stacks->a);
	printf("is sorted: %d\n", i);
	if (!i)
	{
		sort(stacks->a, stacks->b, argc);
	}
	i = is_final(stacks->a);
	printf("is final: %d\n", i);
}
