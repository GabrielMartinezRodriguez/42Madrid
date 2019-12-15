/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:45:37 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 13:08:43 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*print_integers(t_list_flags flags, va_list ap)
{
	int		number;
	char	*str;
	int		size;

	number = (int)va_arg(ap, void *);
	str = ft_itoa((int)number);
	str = str_precision(flags.precision, str);
	size = ft_strlen(str);
	if (flags.sign.active)
		apply_spaces(&str, flags.sign, size, 0);
	else if (flags.cero.active)
	{
		if (!flags.precision.active)
			str = str_ceros(flags.cero, str);
		else
			apply_spaces(&str, flags.cero, size, 1);
	}
	else if (flags.minimum.active)
		apply_spaces(&str, flags.minimum, size, 1);
	return (str);
}

char	*str_ceros(t_flag flag, char *str)
{
	int		size;
	int		sign;
	char	*ret;

	if (flag.active)
	{
		sign = 0;
		size = ft_strlen(str);
		size = flag.number - size;
		if (size > 0)
		{
			ret = malloc(sizeof(char) * (flag.number + 1));
			if (str[0] == '-')
			{
				ret[0] = '-';
				sign = 1;
			}
			ft_memset(&ret[sign], '0', size);
			ft_strlcpy(&ret[sign + size], str + sign, ft_strlen(str) + 1);
			free(str);
			return (ret);
		}
	}
	return (str);
}

char	*str_precision(t_flag flag, char *str)
{
	int		size;
	int		sign;
	char	*ret;

	if (flag.active)
	{
		sign = 0;
		size = ft_strlen(str);
		if (str[0] == '-')
			sign = 1;
		size = flag.number - size + sign;
		if (str[0] == '0' && flag.number == 0)
			return (ft_strdup(""));
		if (size > 0)
		{
			ret = ft_calloc((sizeof(char)), flag.number + sign + 1);
			if (sign)
				ret[0] = '-';
			ft_memset(&ret[sign], '0', size);
			ft_strlcpy(&ret[sign + size], str + sign, ft_strlen(str) + 1);
			free(str);
			return (ret);
		}
	}
	return (str);
}
