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
#define F (stacks->a)->data
#define S (stacks->a->next)->data
#define T ((stacks->a->next)->next)->data

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

	// ft_printf("isdup in find_ms beg %d\n", check_dup_l(stacks->a));
	i = 0;
	bubble_sort(array);
	// ft_printf("isdup in find_ms after bubble sort %d\n", check_dup_l(stacks->a));
	
	// ft_printf("in find ms\n");
	*min = array->arr[0];
	*max = array->arr[array->len - 1];
	*med = array->arr[array->len/2];
	// ft_printf("isdup in find_ms end %d\n", check_dup_l(stacks->a));
	// ft_printf("min %d, med %d, max %d \n", *min, *med, *max);
}

void sort_tripple(t_stacks *stacks)
{

	// 1 3 2
	if (F < S && S > T && F < T)
	{
		sa(stacks);
		ra(stacks);
	}
	// 2 3 1
	else if (F < S && S > T && F > T)
		rra(stacks);
	// 2 1 3
	else if (F > S && S < T && F < T)
		sa(stacks);
	// 3 1 2
	else if (F > S && S < T && F > T)
		ra(stacks);
	// 3 2 1
	else if (F > S && S > T && F > T)
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

	// int	i;

	// int	q = 0;
	// ft_printf("start of fill_b\n");
	// while (arr[q])
	// {
	// 	ft_printf("%d ", arr[q]);
	// 	q++;
	// }

	// ft_printf("isdup in fill_b %d\n", check_dup_l(stacks->a));
	// i = 0;
	// find_extr(stacks->a, &min, &max);
	
	// stacks_printf(stacks->a, stacks->b);

	// ft_printf("_%d_\n", arr[0]);
	
	find_ms(array, &min, &med, &max); //, stacks);
	// ft_printf("isdup in fill_b %d\n", check_dup_l(stacks->a));

	// ft_printf("min: %d; max: %d \n", min, max);
	// ft_printf("b address: %p\n", (*b));
	// ft_printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	
	// stacks_printf(stacks->a, stacks->b);

	while (stacks->la != 3)
	{
		if ((stacks->a)->data != min && (stacks->a)->data != max && (stacks->a)->data != med)
		{
			pb(stacks);
			// ft_printf("pb\n");
		}
		else //if (i + 1 < stacks->la)
		{
			// change to ra
			ra(stacks);
			// ft_printf("ra\n");
		}
		// stacks_printf(stacks->a, stacks->b);
		// i++;
		
	}
	// stacks_printf(stacks->a, stacks->b);
	// ft_printf("min %d, med %d, max %d \n", min, med, max);

	// int	q = 0;
	// ft_printf("start of fill_b\n");
	// while (arr[q])
	// {
	// 	ft_printf("%d ", arr[q]);
	// 	q++;
	// }
	sort_tripple(stacks);
	// stacks_printf(stacks->a, stacks->b);
	// ft_printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	// ft_printf("b address after while: %p\n", (*b));

}
