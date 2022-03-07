/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:54:28 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/07 13:54:29 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

void	choose_cmd(t_stacks *stacks, int cmd)
{
	if (cmd == 0)
		sa(stacks);
	else if (cmd == 3)
		sb(stacks);
	else if (cmd == 6)
		pa(stacks);
	else if (cmd == 9)
		pb(stacks);
	else if (cmd == 12)
		ra(stacks);
	else if (cmd == 15)
		rb(stacks);
	else if (cmd == 18)
		rr(stacks);
	else if (cmd == 21)
		rra(stacks);
	else if (cmd == 25)
		rrb(stacks);
	else if (cmd == 29)
		rrr(stacks);
	else
	{
		ft_printf("Error\n");
		exit(-1);
	}
}

void	parse(t_stacks *stacks)
{
	char		*str;
	char		*p;
	char		*model = "sa\nsb\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	int			cmd;

	str = get_next_line(0);
	while (str)
	{
		p = ft_strstr(model, str);
		if (!p)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		cmd = p - model;
		choose_cmd(stacks, cmd);
		free (str);
		str = get_next_line(0);
	}
}
