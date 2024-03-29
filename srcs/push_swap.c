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
#include "ft_printf.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_arr		*array;
	int			*arr;

	arr = check(argc, argv);
	array = malloc(sizeof(t_arr));
	array->arr = arr;
	array->len = argc - 1;
	stacks = stacks_init(argc, argv);
	if (!is_sorted(stacks->a))
		sort(stacks, array);
	if (!is_final(stacks->a))
		f_sort(stacks);
	free(array->arr);
	free(array);
	free_stacks(stacks);
}
