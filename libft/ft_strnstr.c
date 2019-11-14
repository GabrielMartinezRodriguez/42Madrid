/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:36:28 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/14 18:17:14 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
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
		ptr = (char *)(str + i - j);
	return (ptr);
}
