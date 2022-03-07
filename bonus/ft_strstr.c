/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:51:37 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/13 21:51:38 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_printf.h"
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	size_t	nlen;
	size_t	i;
	size_t	j;

	h = (char *) haystack;
	nlen = (size_t) ft_strlen(needle);
	if (!nlen)
		return (h);
	if (ft_strlen(haystack) < nlen)
		return (NULL);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (needle[j] && needle[j] == h[i + j])
			j++;
		if (j == nlen)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
