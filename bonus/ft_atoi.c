/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:12:05 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/09 13:12:07 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

static int	ft_isspace(char c);
static int	is_negative(char c);
static void	check_max(long int number, int neg, char c, va_list ap);

int	ft_atoi(const char *str, ...)
{
	int				i;
	long int		number;
	int				neg;
	va_list			ap;

	va_start(ap, str);
	i = 0;
	number = 0;
	while (ft_isspace(str[i]))
		i++;
	neg = is_negative(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		check_max(number, neg, str[i], ap);
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return ((int) neg * number);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

static int	is_negative(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static void	check_max(long int number, int neg, char c, va_list ap)
{
	if ((neg == -1 && (number * neg * 10) - c + 48 < INT_MIN)
		|| (neg == 1 && (number * 10) + c - 48 > INT_MAX))
	{
		ft_printf("Error!\n");
		free(va_arg(ap, int *));
		exit (-1);
	}
}
