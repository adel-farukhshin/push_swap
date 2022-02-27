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

static void bubble_sort(int *arr)
{
	int	i;
	int	j;
	int c;

	i = 0;
	j = 1;
	while (arr[i])
	{
		while (arr[j])
		{
			if (arr[j] < arr[i])
			{
				c = arr[j];
				arr[j] = arr[i];
				arr[i] = c;
			}
			j++;
		}
		j = i + 2;
		i++;
	}
}

void	find_ms(int *arr, int *min,  int *med, int *max)
{
	int	i;

	i = 0;
	bubble_sort(arr);
	while (arr[i])
		i++;
	*min = arr[0];
	*max = arr[i - 1];
	*med = arr[i/2];
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

void	fill_b(t_stacks *stacks, int *arr)
{
	int	min;
	int	max;
	int	med;
	// int	i;

	// i = 0;
	// find_extr(stacks->a, &min, &max);
	find_ms(arr, &min, &med, &max);

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
	
	sort_tripple(stacks);
	// stacks_printf(stacks->a, stacks->b);
	// ft_printf("la: %d, lb: %d\n", stacks->la, stacks->lb);
	// ft_printf("b address after while: %p\n", (*b));

}
