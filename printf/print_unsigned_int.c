/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:03:01 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 14:42:07 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*print_unsigned_integers(t_list_flags flags, va_list ap)
{
	unsigned int	number;
	char			*string;
	int				size;

	number = (unsigned int)va_arg(ap, void *);
	string = ft_itoaLong(number);
	string = str_ceros(flags.precision, string);
	size = ft_strlen(string);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
	{
		if (!flags.precision.active)
			string = str_ceros(flags.cero, string);
		else
			apply_spaces(&string, flags.cero, size, 1);
	}
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}
