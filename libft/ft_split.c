/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:53:10 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/11 16:13:51 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**aux;
	char	*ptr;
	int		ini;
	int		seeking;

	aux = malloc(sizeof(char *));
	aux[0] = NULL;
	ini = 0;
	seeking = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (seeking && s[i] != c)
		{
			ini = i;
			seeking = 0;
		}
		if (seeking == 0 && (s[i] == c || s[i + 1] == '\0'))
		{
			seeking = 1;
			ptr = ft_strndup(&s[ini], i - ini);
			aux = ft_insert_string(aux, ptr);
		}
		i++;
	}
	return (aux);
}
