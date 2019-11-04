/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:14:46 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/04 13:27:05 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *mem, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char*)mem;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)0;
		i++;
	}
}
