/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:17:12 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/15 18:15:38 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# define BUFFER_SIZE 16

typedef struct	s_read_history
{
	int				fd;
	char			*str;
	struct s_read_history	*next;
}				t_list_fd;

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif