/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:38:15 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/11 13:51:47 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int             itoa2(int n, char **str, int *sign,long int *num);

static int		itoa2(int n, char **str, int *sign,long int *num)
{
	int size;
	long int cpy;

	size = 0;
	*sign = 0;
	if (n < 0)
	{
		*num = -((long int)n);
		*sign = 1;
	}
	else
		*num = n;
	cpy = *num;
	if (n == 0)
		size = 1;
	while (cpy != 0)
	{
		size++;
		cpy = cpy / 10;
	}
	*str = malloc(size + 1 + *sign);
	return (size);
}


char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	i;
	long int		cpy;
	int				sign;
	char			*aux;

	size = itoa2 (n,&aux, &sign, &cpy);
	if (sign == 1)
		aux[0] = '-';
	i = 0;
	while (i++ < size)
	{
		aux[size - i + sign] = (cpy % 10) + '0';
		cpy = cpy / 10;
	}
	aux[size + sign] = '\0';
	return (aux);
}

