/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:41:42 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/14 18:10:15 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	if (destination == NULL && source == NULL)
		return (NULL);
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
