/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:22:56 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 13:42:33 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	i;

	aux = malloc(len + 1);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		aux[i] = s[start + i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
