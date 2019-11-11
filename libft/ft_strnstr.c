/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:36:28 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/11 21:25:49 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	int		find;
	size_t	i;
	int		j;
	char	*ptr;

	ptr = NULL;
	find = 0;
	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		find = 1;
	while (str[i] != '\0' && find == 0 && i < len)
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		if (to_find[j] == '\0')
			find = 1;
		i++;
	}
	if (find == 1)
		ptr = str + i - j;
	return (ptr);
}
