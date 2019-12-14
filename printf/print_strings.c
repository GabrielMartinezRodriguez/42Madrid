/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:55:56 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 18:58:39 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*print_string(t_list_flags flags, va_list ap)
{
	char	*string;
	int		size;

	string = (char *)va_arg(ap, void *);
	if(string == NULL)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(string);
	if (flags.precision.active)
		string = string_precision(string, flags.precision.number);
	size = ft_strlen(string);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
		string = apply_ceros(flags.cero, string);
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}

char		*string_precision(char *string, int number)
{
	char *cpy;

	cpy = string;
	string  = ft_substr(string, 0, number);
	free(cpy);
	return(string);
}