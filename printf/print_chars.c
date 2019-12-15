/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:41:01 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 13:17:34 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*print_char(t_list_flags flags, va_list ap)
{
	char	*string;
	char	c;
	int		size;

	size = 1;
	c = (char)va_arg(ap, void *);
	string = char_to_string(c);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
		string = apply_ceros(flags.cero, string);
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}

char	*char_to_string(char c)
{
	char *str;

	if (c != '\0')
	{
		str = ft_calloc(1, 2);
		str[0] = c;
	}
	else
	{
		str = ft_strdup("null");
		null_case(0, 1);
	}
	return (str);
}

int		null_case(int get, int set)
{
	static int null_case = 0;

	if (get == 1)
		return (null_case);
	else if (set == 1)
		null_case = set;
	return (0);
}
