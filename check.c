
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

static int	check_nb(int argc, char **argv, int *arr)
{
	int	j;
	int	i;

	i = 0;
	j = 0;

	while (argc - 1)
	{
		while (argv[argc - 1][j])
		{
			if (!ft_isdigit(argv[argc - 1][j]))
			{
				free(arr);
				return (-1);
			}
			j++;
		}
		arr[argc - 2] = ft_atoi(argv[argc - 1]);
		j = 0;
		i++;
		argc--;
	}
	return (i);
}

static int	check_dup(int i, int *arr)
{
	int	j;

	j = 0;
	while (i)
	{
		while (j < i - 1)
		{
			// printf ("j %d; i - 1 %d\n", arr[j], arr[i - 1]);
			if (arr[j] == arr[i - 1])
			{
				free(arr);
				return (-1);
			}
			j++;
		}
		j = 0;
		i--;
	}
	return (0);
}

int	check (int argc, char **argv)
{
	int	*arr;
	int	i;

	if (argc == 1)
		exit (-1);
	arr = (int *) malloc(sizeof(int *) + (argc - 1) * sizeof(int));
	i = check_nb(argc, argv, arr);
	if (i == -1)
		exit (-1);
	i = check_dup(i, arr);
	if (i == -1)
		exit (-1);
	free(arr);
	return (1);
}