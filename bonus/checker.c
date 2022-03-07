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

void	parse(t_stacks *stacks)
{
	char		*str;
	char		*p;
	char		*model = "sa\nsb\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";

	str = get_next_line(0);
	while (str)
	{
		p = ft_strstr(model, str);
		if (!p)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		
		ft_printf("%s", p);
		free (str);
		str = get_next_line(0);
		
	}
	stacks_printf(stacks->a, stacks->b);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	

	check(argc, argv);
	stacks = stacks_init(argc, argv);
	parse(stacks);
	stacks_printf(stacks->a, stacks->b);
	free_stacks(stacks);
}
