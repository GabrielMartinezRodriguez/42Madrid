/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:10:48 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/14 18:09:57 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = (unsigned char *)str;
	i = 0;
	while (i < n && src[i] != (unsigned char)c)
		i++;
	if (n != i)
		return ((void *)(str + i));
	else
		return (NULL);
}
