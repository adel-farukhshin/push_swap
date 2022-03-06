/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:49:21 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/27 15:49:22 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	scorea(t_stack *a, int la, t_stack *cur)
{
	int	pos;
	int	tpos;

	pos = 1;
	tpos = 0;
	while (a->next)
	{
		if (cur->data > a->data && cur->data < (a->next)->data)
			tpos = pos;
		pos++;
		a = a->next;
	}
	pos = tpos;
	if (pos > la / 2)
		cur->ascore = -(la - pos);
	else
		cur->ascore = pos;
}

void	score(t_stacks *stacks)
{
	int	pos;
	t_stack	*tmp;

	tmp = stacks->b;
	pos = 0;
	while (tmp)
	{
		if (pos > (stacks->lb) / 2)
			tmp->bscore = -(stacks->lb - pos);
		else
			tmp->bscore = pos;
		scorea(stacks->a, stacks->la, tmp);
		// ft_printf("_ %d %d _ ", tmp->ascore, tmp->bscore);
		pos++;
		tmp = tmp->next;
	}
	// ft_printf("\n");
}
