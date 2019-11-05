/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:21:47 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/05 13:40:36 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;

	i = 0;
	while (str1[i] == str2[i] && i < num)
		i++;
	if (i == num)
		return (0);
	else
		return (str1[i] - str2[i]);
}
