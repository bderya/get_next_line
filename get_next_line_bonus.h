/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:24:27 by bderya            #+#    #+#             */
/*   Updated: 2022/05/08 18:20:24 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
size_t		ft_strlen(char *s);
char		*get_rest(char	*string);
char		*get_line(char *string);
char		**get_read_line(int fd, char *string);

#endif
