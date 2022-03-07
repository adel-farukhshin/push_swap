/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:57:06 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/20 16:57:10 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(const char *s)
{
	unsigned long	a;

	a = 0;
	while (*s)
	{
		a++;
		s++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	ret = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (NULL);
	tmp = (char *) s1;
	while (tmp[i])
	{
		ret[i] = tmp[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*r;

	a = (char) c;
	r = (char *) s;
	while (*r)
	{
		if (*r == a)
		{
			return (r);
		}
		r++;
	}
	if (a == '\0')
		return (r);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	unsigned long	i;
	char			*str;

	if (!s1 || !s2)
		return ((char *) s1);
	i = ft_strlen(s1);
	i += ft_strlen(s2);
	str = malloc(i + 1);
	if (!str)
		return (str);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
