/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:17:15 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/15 18:34:31 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int             i;
	int             flag;
	t_list_fd  *element;
	char			*str;
	static t_list_fd  *list = NULL;

	element = ft_find_fd(fd, list);
	if(!errors_and_ini(fd, element, &str, &flag) || line == NULL)
		return (-1);
	while(flag)
	{
		i = 0;
		while(str[i] != '\0' && str[i++] != '\n');
		
	}

}

static int errors_and_ini(int fd, t_list_fd *lst, char **str, int *flag)
{
	int i;

	*flag = 1;
	*str = malloc(BUFFER_SIZE + 1);
	if(str == NULL || fd < 0)
		return (0);
	i = 0;
	while(i < BUFFER_SIZE + 1)
	{
		str[i] = '\0';
		i++;
	}
	ft_strlcpy(*str, lst->str, ft_strlen(lst->str) + 1);
	return (1);
}

