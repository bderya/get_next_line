/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:01:48 by bderya            #+#    #+#             */
/*   Updated: 2022/04/28 05:35:27 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if ((char)c == *s)
	{
		return ((char *)s);
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = (char *)malloc
			(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!ret)
			return (NULL);
		return (ret);
	}
	return (NULL);
}
