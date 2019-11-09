/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:37 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 18:56:03 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strndup(const char *str1, int n)
{
	char	*aux;
	int		i1;
	int		i2;

	i1 = 0;
	while (str1[i1] != '\0')
		i1++;
	aux = malloc(i1 + 1);
	i2 = 0;
	while (i2 < i1 && i2 < n)
	{
		aux[i2] = str1[i2];
		i2++;
	}
	aux[i1] = '\0';
	return (aux);
}
