/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:41:12 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/27 15:41:14 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// #define F (stacks->a)->data
// #define S (stacks->a->next)->data
// #define T ((stacks->a->next)->next)->data

static void bubble_sort(t_arr *array)
{
	int	i;
	int	j;
	int c;

	i = 0;
	j = 1;
	while (i < array->len)
	{
		while (j < array->len)
		{
			if (array->arr[j] < array->arr[i])
			{
				c = array->arr[j];
				array->arr[j] = array->arr[i];
				array->arr[i] = c;
			
			}
			j++;
		}
		j = i + 2;
		i++;
	}
}

void	find_ms(t_arr *array, int *min,  int *med, int *max) // , t_stacks *stacks)
{
	int	i;

	i = 0;
	bubble_sort(array);
	*min = array->arr[0];
	*max = array->arr[array->len - 1];
	*med = array->arr[array->len/2];
	// ft_printf("min %d, med %d, max %d \n", *min, *med, *max);
}

void sort_tripple(t_stacks *stacks)
{
	int	f;
	int	s;
	int	t;

	f = (stacks->a)->data;
	s = (stacks->a->next)->data;
	t = ((stacks->a->next)->next)->data;
	// 1 3 2
	if (f < s && s > t && f < s)
	{
		sa(stacks);
		ra(stacks);
	}
	// 2 3 1
	else if (f < s && s > t && f > t)
		rra(stacks);
	// 2 1 3
	else if (f > s && s < t && f < t)
		sa(stacks);
	// 3 1 2
	else if (f > s && s < t && f > t)
		ra(stacks);
	// 3 2 1
	else if (f > s && s > t && f > t)
	{
		sa(stacks);
		rra(stacks);
	}
}

void	fill_b(t_stacks *stacks, t_arr *array)
{
	int	min;
	int	max;
	int	med;

	// stacks_printf(stacks->a, stacks->b);
	find_ms(array, &min, &med, &max);
	while (stacks->la != 3)
	{
		if ((stacks->a)->data != min && (stacks->a)->data != max && (stacks->a)->data != med)
		{
			pb(stacks);
			if ((stacks->b)->data > med)
				rb(stacks);
		}
		else
		{
			ra(stacks);
		}
	}
	// stacks_printf(stacks->a, stacks->b);
	sort_tripple(stacks);
	// stacks_printf(stacks->a, stacks->b);
}
