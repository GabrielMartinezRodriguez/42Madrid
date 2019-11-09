/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:38:15 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 21:11:06 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int itoa2(int n, char **str, int *sign,long int *num);

char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	i;
	long int		cpy;
	int				sign;
	char			*aux;

	size = itoa2(n,&aux, &sign, &cpy);
	if(sign)
		aux[0] = '-';
	while (i++ < size - 1)
	{
		aux[size - i - 2 + sign] = (cpy % 10) + '0';
		cpy /= 10;
	}
	aux[size - 1] = '\0';
	return (aux);
}
int		itoa2(int n, char **str, int *sign,long int *num)
{
	int size;

	size = 0;
	sign = 0;
	if (n < 0)
	{
		*num = -n;
		sign = 1;
	}
	else
		*num = n;
	if (n == 0)
		size = 1;
	if (num == 0)
		size = 1;
	while (*num != 0)
	{
		size++;
		*num = *num / 10;
	}
	*str = malloc(size + 1 + *sign);
	return (size);
}
