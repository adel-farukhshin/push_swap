/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:00:44 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/07 11:00:45 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>


int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	check(argc, argv);
	stacks = stacks_init(argc, argv);
	parse(stacks);
	stacks_printf(stacks->a, stacks->b);
	free_stacks(stacks);
}
