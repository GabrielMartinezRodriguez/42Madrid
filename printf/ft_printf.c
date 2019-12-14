/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:32:16 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 14:47:41 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
	char *s = "este es el string";
	ft_printf("ft_printf %s y este es su puntero:%p\n",s,s);
	printf("printf %s y este es su puntero:%p\n",s,s);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		chars_n;
	char	*buff;

	va_start(ap, str);
	i = 0;
	chars_n = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i += print_variable((char *)(&str[i]), ap, &buff);
			chars_n += show_str(buff, ft_strlen(buff));
			free(buff);
		}
		else
			chars_n += show_str((char *)(&str[i]), 1);
		i++;
	}
	return (chars_n);
}

int		show_str(char *buff, unsigned int len)
{
	write(1, buff, len);
	return (len);
}
