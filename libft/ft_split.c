/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:53:10 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 19:58:56 by gmartine         ###   ########.fr       */
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

	aux = NULL;
	ini = 0;
	seeking = 1;
	i = 0;
	while (s[i++] != '\0')
	{
		if (seeking && s[i - 1] != c)
		{
			ini = i - 1;
			seeking = 0;
		}
		else if (seeking == 0 && (s[i - 1] == c || s[i] == '\0'))
		{
			seeking = 1;
			ptr = ft_strndup(&s[i], i - ini - 1);
			aux = ft_insert_string(aux, ptr);
		}
	}
	return (aux);
}
