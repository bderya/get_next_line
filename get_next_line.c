/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:42:45 by bderya            #+#    #+#             */
/*   Updated: 2022/04/28 05:30:10 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


char	*get_read_line(int fd, char *str)
{
	char *temp;
	int t_fd;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!temp)
		return (NULL);
	while(ft_strchr(str, '\n'))
	{
		t_fd = read(fd, temp, BUFFER_SIZE);
		if(t_fd == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[t_fd] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_row(char *string)
{
	int count;
	char *line;
	
	count = 0;
	if (!string[count])
		return (NULL);
	while (string[count] && string[count] != '\0')
		count++;
	line = malloc(count * sizeof(char));
	if (!line)
		return (NULL);
	count = 0;
	while (string[count] && string[count] != '\0')
	{
		line[count] = string[count];
		count++;
	}
	if (string[count] == '\n')
	{
		line[count] = string[count];
		count++;
	}
	line[count] = '\0';
	return (line);
}
 
char	*get_next_line(int fd)
{
	static char *string;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = get_read_line(fd, string);
	if(!string)
		return(NULL);
	line = get_row(string);
	return (line);
}
