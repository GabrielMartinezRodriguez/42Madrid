/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:44:53 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/04 17:45:35 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned char	inter[num];
	size_t			i;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	while (i < num)
	{
		inter[i] = src[i];
		i++;
	}
	i = 0;
	while (i < num)
	{
		dest[i] = inter[i];
		i++;
	}
	return (destination);
}
