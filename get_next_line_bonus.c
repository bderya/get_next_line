/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:42:45 by bderya            #+#    #+#             */
/*   Updated: 2022/05/08 18:37:50 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_line(int fd, char *string)
{
	char	*temp;
	int		byte_size;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	byte_size = 1;
	while (!ft_strchr(string, '\n') && (byte_size != 0))
	{
		byte_size = read(fd, temp, BUFFER_SIZE);
		if (byte_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[byte_size] = '\0';
		string = ft_strjoin(string, temp);
	}
	free(temp);
	return (string);
}

char	*get_line(char *string)
{
	int		i;
	char	*line;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *string)
{
	char	*restof;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (ft_strlen(string) - i + 1));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (string[i])
		restof[j++] = string[i++];
	restof[j] = '\0';
	free(string);
	return (restof);
}

char	*get_next_line(int fd)
{
	static char	*string[1024];
	char		*line;

	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0
		|| (read(fd, 0, 0) == -1))
		return (0);
	*(string + fd) = get_read_line(fd, *(string + fd));
	if (!*(string + fd))
		return (NULL);
	line = get_line(*(string + fd));
	*(string + fd) = get_rest(*(string + fd));
	return (line);
}
