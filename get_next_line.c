/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:42:45 by bderya            #+#    #+#             */
/*   Updated: 2022/04/20 21:20:54 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"





char	*get_next_line(int fd)
{
	char *string;

	if(fd != 0 || BUFFER_SIZE <= 0)
		return (-1);
	string =
}