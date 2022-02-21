/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:46 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:04:48 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"
#include <stdlib.h>

t_stacks	*stacks_init(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;
	t_stack 	*tmp;
	
	stacks = malloc(sizeof(t_stacks *));
	

	i = 1;
	stacks->a = NULL;
	while (i < argc)
	{
		tmp = lstnew(ft_atoi(argv[i]));
		lstadd_back(&(*stacks).a, tmp);
		i++;
	}
	stacks->b = NULL;
	stacks->la = i - 1;
	stacks->lb = 0;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	t_stack	*tmp;

	while(stacks->a)
	{
		tmp = stacks->a;
		stacks->a = (stacks->a)->next;
		free(tmp);
	}
	while(stacks->b)
	{
		tmp = stacks->b;
		stacks->b = (stacks->b)->next;
		free(tmp);
	}
	free(stacks);
}