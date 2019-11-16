/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:42:44 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/16 17:28:22 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	i;
	size_t	t_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t_s2 = ft_strlen(s2);
	aux = malloc(ft_strlen(s1) + t_s2 + 1);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		aux[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < t_s2)
	{
		aux[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	aux[i + ft_strlen(s1)] = '\0';
	return (aux);
}
