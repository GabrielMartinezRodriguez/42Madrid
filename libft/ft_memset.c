/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:40:43 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/14 18:10:27 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int byte, size_t len)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*str;

	c = (unsigned char)byte;
	str = (unsigned char*)mem;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (mem);
}
