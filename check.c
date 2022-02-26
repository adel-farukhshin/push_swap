/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:03:31 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:03:34 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_printf.h"
#include "push_swap.h"

// put error (in strerror): not integer, bigger than int, dupes
// else: prompt back
static void	check_nb(int argc, char **argv, int *arr)
{
	int	j;
	int	i;

	i = 0;
	j = 0;

	while (argc - 1)
	{
		while (argv[argc - 1][j])
		{
			if (!ft_isdigit(argv[argc - 1][j]) && (argv[argc - 1][0] != '-'))
			{
				free(arr);
				ft_printf("Error!\n");
				exit (-1);
			}
			j++;
		}
		arr[argc - 2] = ft_atoi(argv[argc - 1]);
		j = 0;
		i++;
		argc--;
	}
}

static void	check_dup(int i, int *arr)
{
	int	j;

	j = 0;
	while (i)
	{
		while (j < i - 1)
		{
			// ft_printf ("j %d; i - 1 %d\n", arr[j], arr[i - 1]);
			if (arr[j] == arr[i - 1])
			{
				free(arr);
				ft_printf("Error!\n");
				exit (-1);
			}
			j++;
		}
		j = 0;
		i--;
	}
}

void	check (int argc, char **argv)
{
	int	*arr;

	if (argc == 1)
		exit (-1);
	arr = (int *) malloc(sizeof(int *) + (argc - 1) * sizeof(int));
	check_nb(argc, argv, arr);
	check_dup(argc - 1, arr);
	free(arr);
}
