/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:56:46 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/18 11:56:48 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_create_line(char *str, char **line)
{
	char	*n_adress;
	char	*tmp;

	n_adress = ft_strchr(str, '\n');
	if (n_adress)
	{
		*n_adress = '\0';
		n_adress++;
	}
	tmp = *line;
	*line = ft_strjoin(*line, str);
	if (tmp)
		free(tmp);
	tmp = *line;
	if (n_adress)
	{
		*line = ft_strjoin(*line, "\n");
		if (tmp)
			free(tmp);
	}
	return (n_adress);
}

void	ft_free_line(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
}

char	*ft_read_line(int fd, char **line)
{
	int		bytes_read;
	char	*surplus;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	surplus = NULL;
	while (surplus == NULL && line)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
		{	
			if ((**line == '\0') || bytes_read < 0)
				ft_free_line(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_create_line(buffer, line);
		if (tmp)
			surplus = ft_strdup(tmp);
	}
	return (surplus);
}

char	*get_next_line(int fd)
{
	static char	*surplus;
	char		*line;
	char		*n_a;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(sizeof(char *) + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (surplus)
	{
		n_a = ft_create_line(surplus, &line);
		temp = surplus;
		surplus = ft_strdup(n_a);
		free(temp);
	}
	else
		surplus = NULL;
	if (surplus == NULL)
		surplus = ft_read_line(fd, &line);
	return (line);
}
