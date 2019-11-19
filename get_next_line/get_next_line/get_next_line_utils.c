/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:07:04 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/19 19:01:05 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char *p;

	if (n != 0)
	{
		p = s;
		while (n-- != 0)
		{
			if (*p++ == (char)c)
				return ((void *)(p - 1));
		}
	}
	return (NULL);
}

char			*ft_strdup(const char *str1)
{
	char	*aux;
	int		i1;
	int		i2;

	i1 = 0;
	while (str1[i1] != '\0')
		i1++;
	aux = malloc(i1 + 1);
	if (aux == NULL)
		return (NULL);
	i2 = 0;
	while (i2 < i1)
	{
		aux[i2] = str1[i2];
		i2++;
	}
	aux[i1] = '\0';
	return (aux);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		i;
	int		t_s[2];

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t_s[0] = ft_strlen(s2);
	t_s[1] = ft_strlen(s1);
	aux = malloc(t_s[1] + t_s[0] + 1);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (i < t_s[1])
	{
		aux[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < t_s[0])
	{
		aux[i + t_s[1]] = s2[i];
		i++;
	}
	aux[i + t_s[1]] = '\0';
	return (aux);
}

size_t			ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*(str++))
		;
	return ((s == NULL) ? 0 : (size_t)(str - s - 1));
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	size_t		n;

	if (dst == NULL || src == NULL)
		return ((size_t)((src == NULL) ? src : dst));
	s = src;
	n = dstsize;
	if (n != 0)
		while (--n != 0)
			if ((*dst++ = *src++) == '\0')
				break ;
	if (n == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return ((size_t)(src - s - 1));
}
