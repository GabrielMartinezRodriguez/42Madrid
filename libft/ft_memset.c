/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:40:43 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/04 12:49:09 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *mem, int byte, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char*)mem;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)byte;
		i++;
	}
	return (mem);
}
