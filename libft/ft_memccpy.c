/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:16:37 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/06 17:35:46 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *destination, const void *source, int c, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	while (i < num && (i == 0 || (src[i - 1] != (unsigned char)c)))
	{
		dest[i] = src[i];
		i++;
	}
	if (!(src[i - 1] != (unsigned char)c))
		return (destination + i);
	else
		return (NULL);
}
