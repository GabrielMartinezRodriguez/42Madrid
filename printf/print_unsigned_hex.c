/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:00:11 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 19:41:28 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*print_unsigned_hex(t_list_flags flags, va_list ap)
{
	unsigned int	number;
	char			*string;
	int				size;

	number = (unsigned int)va_arg(ap, void *);
	string = unsigned_to_hex(number);
	if (flags.precision.active)
		string = (string[0] == '0' && ft_strlen(string) == 1 && flags.precision.number == 0) ? ft_strdup("") : apply_ceros(flags.precision, string);
	size = ft_strlen(string);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
	{
		if (!flags.precision.active)
			string = apply_ceros(flags.cero, string);
		else
			apply_spaces(&string, flags.cero, size, 1);
	}
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}

char	*unsigned_to_hex(unsigned int number)
{
	unsigned int	cpy;
	unsigned int	tam;
	unsigned int	i;
	char			*string;

	tam = 0;
	cpy = number;
	if (cpy == 0)
		tam = 1;
	while (cpy > 0)
	{
		cpy /= 16;
		tam++;
	}
	string = ft_calloc(sizeof(char), tam + 1);
	i = 0;
	while (i < tam)
	{
		string[tam - i - 1] = byte_to_hex(number % 16);
		number /= 16;
		i++;
	}
	return (string);
}
