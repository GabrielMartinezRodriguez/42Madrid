/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:36:28 by gmartine          #+#    #+#             */
/*   Updated: 2019/09/12 19:59:11 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		find;
	int		i;
	int		j;
	char	*ptr;

	ptr = NULL;
	find = 0;
	i = 0;
	if (to_find[0] == '\0')
		find = 1;
	while (str[i] != '\0' && find == 0)
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
