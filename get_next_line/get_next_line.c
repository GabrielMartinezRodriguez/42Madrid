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


static t_list_fd *ft_find_fd(int fd, t_list_fd **list)
{
	int			flag;
	t_list_fd	*aux;

	flag = 1;
	aux = *list;
	
	while(!aux && flag)
	{
		if(fd == aux->fd)
			flag = 0;
		else
			aux = aux->next;
	}
	if(flag != 0)
	{
		aux = malloc(sizeof(t_list_fd));
		aux->fd = fd;
		aux->next = *list;
		aux->str = ft_substr("", 0, 1);
		*list = aux;
	}
	return(aux);
}

static int errors_and_ini(int fd, t_list_fd *lst, char ***str, int *flag)
{
	int i;

	*flag = 1;

	*str = malloc(sizeof(char *) * 3);
	(*str)[0] = malloc(BUFFER_SIZE + 1);
	(*str)[1] = ft_substr("", 0, 1);
	(*str)[2] = (*str)[1];
	if(str == NULL || fd < 0)
		return (0);
	i = 0;
	while(i < BUFFER_SIZE + 1)
	{
		(*str)[0][i] = '\0';
		i++;
	}
	ft_strlcpy((*str)[0], lst->str, ft_strlen(lst->str) + 1);
	return (1);
}

static int read_fd(int fd, char **str, int *i, int *flag)
{
	int len;


	len = 0;
	len = read(fd, str[0], BUFFER_SIZE);
	if(len < 0)
		return (-1);
	else if(len == 0)
		*flag = 0;
	else
	{
		str[len] = '\0';
		*i = 0;
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	int             i;
	int             flag;
	t_list_fd		*element;
	char			**str; /* 3 strings: 0 - Buffer de lectura. 1 - Linea. 2 - Aux */
	static t_list_fd  *list = NULL;

	element = ft_find_fd(fd, &list);
	if(!errors_and_ini(fd, element, &str, &flag) || line == NULL)
		return (-1);
	while(flag)
	{
		i = 0;
		while(str[0][i++] != '\0' && str[0][i - 1] != '\n');
		if(str[0][--i] == '\n')
			flag = 0;
		str[0][i] = '\0';
		str[1] = ft_strjoin(str[1], str[0]);
		free(str[2]);
		str[2] = str[1];
		if(flag == 1 && read_fd(fd, str, &i, &flag) < 0)
			return (-1);
		else if(flag == 0)
			i++;
	}

}

