/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:37 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:04:39 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include <stdio.h>

void find_extr(t_stack *a, int *min, int *max)
{
	*min = a->data;
	*max = a->data;
	while (a)
	{
		if (a->data > *max)
			*max = a->data;
		if (a->data < *min)
			*min = a->data;
		a = a->next;
	}
}

void	fill_b(t_stacks *stacks)
{
	int	min;
	int	max;
	// int	i;

	// i = 0;
	find_extr(stacks->a, &min, &max);
	printf("min: %d; max: %d \n", min, max);
	// printf("b address: %p\n", (*b));
	printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	stacks_printf(stacks->a, stacks->b);

	while (stacks->la != 2)
	{
		if ((stacks->a)->data != min && (stacks->a)->data != max)
		{
			pb(stacks);
			printf("pb\n");
		}
		else //if (i + 1 < stacks->la)
		{
			r(&(*stacks).a);
			printf("ra\n");
		}
		stacks_printf(stacks->a, stacks->b);
		// i++;
		
	}
	
	printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	// printf("b address after while: %p\n", (*b));

}

void	scorea(t_stack *a, int la, t_stack *cur)
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
		// printf("_ %d %d _ ", tmp->ascore, tmp->bscore);
		pos++;
		tmp = tmp->next;
	}
	// printf("\n");
}

void	fill_pos(t_stacks *stacks)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	// printf("fill_pos\n_________________\n");
	// printf("a : ");
	tmp = stacks->a;
	while (tmp)
	{
		tmp->ps = pos;
		// printf(" %d ", tmp->ps);
		pos++;
		tmp = tmp->next;
	}
	pos = 0;
	// printf("\nb : ");
	tmp = stacks->b;
	while (tmp)
	{
		tmp->ps = pos;
		// printf(" %d ", tmp->ps);
		pos++;
		tmp = tmp->next;
	}
	
}

int	mod(int q)
{
	if (q < 0)
		return (q * (-1));
	else
		return (q);
}


t_stack *sum(t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while(b)
	{
		if ((mod(tmp->ascore) + mod(tmp->bscore)) >
			(mod(b->ascore) + mod(b->bscore)))
			tmp = b;
		b = b->next;
	}
	return (tmp);
}

void perform(t_stacks *stacks)
{
	t_stack *cur;

	cur = sum(stacks->b);
	while (cur->bscore > 0)
	{
		rb(stacks);
		cur->bscore--;
	}
	while (cur->bscore < 0)
	{
		rrb(stacks);
		cur->bscore++;
	}

	while (cur->ascore > 0)
	{
		ra(stacks);
		cur->ascore--;
	}
	while (cur->ascore < 0)
	{
		rra(stacks);
		cur->ascore++;
	}
	// rb(stacks);
	// ra(stacks);
	// stacks_printf(stacks->a, stacks->b);
	// rra(stacks);
	// rrb(stacks);
	// stacks_printf(stacks->a, stacks->b);
	// printf("%d ", cur->data);
	
}

void sort(t_stacks *stacks)
{
	fill_b(stacks);
	// fill_b(&(*stacks).a, &(*stacks).b, stacks->la);
	while(stacks->b)
	{
		// printf("b address after fill_b: %p\n", b);
		// printf("after fill b\n");
		stacks_printf(stacks->a, stacks->b);
		score(stacks);
		ascore_printf(stacks->b);
		bscore_printf(stacks->b);
		// printf("after score\n");
		fill_pos(stacks);
		// pos_printf(stacks->a);
		// pos_printf(stacks->b);

		perform(stacks);
		pa(stacks);
	}
	// pa(stacks);
	stacks_printf(stacks->a, stacks->b);
	// stacks_printf(stacks->a, stacks->b);
	// printf("b: ");
	// bscore_printf(stacks->b);
	// stacks_printf(a, b);
	
	// s(&a);
	// stack_printf(a);
	// s(&a);
	// stack_printf(a);
	// printf("\n");
	// p(&a, &b);
	// p(&a, &b);
	// stacks_printf(a, b);
	// p(&b, &a);
	// stacks_printf(a, b);
	// r(&a);
	// printf("\n----------\n");
	// stack_printf(a);
	// rr(&a);
	// printf("\n----------\n");
	// stack_printf(a);

}
