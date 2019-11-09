/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:28:24 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 13:46:56 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	int		i;
	int		j;
	int		flag;
	int		k;

	aux = malloc(ft_strlen(s1) + 1);
	i = 0;
	k = 0;
	while (s1[i++] != '\0')
	{
		j = 0;
		flag = 1;
		while (set[j] != '\0' && flag)
		{
			if (set[j] == s1[i])
				flag = 0;
			j++;
		}
		if (flag && ++k)
			aux[k - 1] = s1[i];
	}
	aux[k - 1] = '\0';
	return (aux);
}
