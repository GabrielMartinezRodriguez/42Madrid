/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:55:56 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 14:43:18 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*print_string(t_list_flags flags, va_list ap)
{
	char	*string;
	char	*cpy;
	int		size;

	string = (char *)va_arg(ap, void *);
	string = ft_strdup(string);
	if (flags.precision.active)
	{
		cpy = string;
		string = ft_substr(string, 0, flags.precision.number);
		free(cpy);
	}
	size = ft_strlen(string);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
		string = apply_ceros(flags.cero, string);
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}
