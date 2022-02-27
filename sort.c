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

#include "ft_printf.h"


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
	// ft_printf("tp %d, p %d\n", tpos, pos);
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

void	fill_pos(t_stacks *stacks)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	// ft_printf("fill_pos\n_________________\n");
	// ft_printf("a : ");
	tmp = stacks->a;
	while (tmp)
	{
		tmp->ps = pos;
		// ft_printf(" %d ", tmp->ps);
		pos++;
		tmp = tmp->next;
	}
	pos = 0;
	// ft_printf("\nb : ");
	tmp = stacks->b;
	while (tmp)
	{
		tmp->ps = pos;
		// ft_printf(" %d ", tmp->ps);
		pos++;
		tmp = tmp->next;
	}
}

void sort(t_stacks *stacks, int *arr)
{
	fill_b(stacks, arr);
	// fill_b(&(*stacks).a, &(*stacks).b, stacks->la);
	while(stacks->b)
	{
		// ft_printf("b address after fill_b: %p\n", b);
		// ft_printf("after fill b\n");
		
		// stacks_printf(stacks->a, stacks->b);
		
		score(stacks);
		
		// ascore_printf(stacks->b);
		// bscore_printf(stacks->b);
		
		// ft_printf("after score\n");
		fill_pos(stacks);
		// pos_printf(stacks->a);
		// pos_printf(stacks->b);

		perform(stacks);
		pa(stacks);
	}
	// pa(stacks);
	
	// stacks_printf(stacks->a, stacks->b);
	
	// stacks_printf(stacks->a, stacks->b);
	// ft_printf("b: ");
	// bscore_printf(stacks->b);
	// stacks_printf(a, b);
	
	// s(&a);
	// stack_printf(a);
	// s(&a);
	// stack_printf(a);
	// ft_printf("\n");
	// p(&a, &b);
	// p(&a, &b);
	// stacks_printf(a, b);
	// p(&b, &a);
	// stacks_printf(a, b);
	// r(&a);
	// ft_printf("\n----------\n");
	// stack_printf(a);
	// rr(&a);
	// ft_printf("\n----------\n");
	// stack_printf(a);

}

void f_sort(t_stacks *stacks)
{
	int	pos;
	int	tpos;
	int	min;
	t_stack *tmp;

	pos = 0;
	tpos = 0;
	tmp = stacks->a;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			tpos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	pos = tpos;
	// ft_printf("pos %d\n", pos);
	if (pos > stacks->la / 2)
		pos = -(stacks->la - pos);
	// ft_printf("pos %d\n", pos);
	while (pos > 0)
	{
		ra(stacks);
		pos--;
	}
	// ft_printf("after -- pos %d\n", pos);
	while (pos < 0)
	{
		rra(stacks);
		pos++;
	}
	// ft_printf("after ++ pos %d\n", pos);
	// stacks_printf(stacks->a, stacks->b);

}