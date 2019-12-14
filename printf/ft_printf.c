/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:32:16 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 13:40:26 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		chars_n;
	int		len;
	char	*buff;

	va_start(ap, str);
	i = 0;
	chars_n = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i += printVariable((char *)(&str[i]), ap, &buff);
			chars_n += show_str(buff, ft_strlen(buff));
			free(buff);
		}
		else
			chars_n += show_str(chars_n, 1);
		i++;
	}
	return (chars_n);
}

int		show_str(char *buff, unsigned int len)
{
	write(1, buff, len);
	return (len);
}
