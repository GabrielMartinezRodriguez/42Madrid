/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:42:44 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 11:50:59 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		i;
	int		t_s1;
	int		t_s2;

	t_s1 = ft_strlen(s1);
	t_s2 = ft_strlen(s2);
	aux = malloc(t_s1 + t_s2 + 1);
	i = 0;
	while (i < t_s1)
	{
		aux[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < t_s2)
	{
		aux[i + t_s1] = s2[i];
		i++;
	}
	aux[i + t_s1] = '\0';
	return (aux);
}
