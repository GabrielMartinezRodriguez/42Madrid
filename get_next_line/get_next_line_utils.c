/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:17:17 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/15 18:14:42 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		i;
	int		t_s2;

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

int		ft_strlen(const char *str)
{
	int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	int				ret;

	if (src == NULL)
		return (0);
	if (dest == NULL)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	ret = i;
	i = 0;
	while (i < size - 1 && src[i] != '\0' && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	i;
	size_t			size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	aux = malloc(len + 1);
	if (aux == NULL)
		return (NULL);
	if (start < size)
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			aux[i] = s[start + i];
			i++;
		}
		aux[i] = '\0';
	}
	else
		return (ft_substr("", 0, 1));
	return (aux);
}