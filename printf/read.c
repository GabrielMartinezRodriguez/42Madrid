/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:03:53 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 12:33:04 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*render_variable(char c, t_list_flags flags, va_list ap)
{
	char *returned;

	if (c == 'i' || c == 'd')
		returned = print_integers(flags, ap);
	else if (c == 's')
		returned = print_string(flags, ap);
	else if (c == 'c')
		returned = print_char(flags, ap);
	else if (c == 'p')
		returned = print_pointer(flags, ap);
	else if (c == 'u')
		returned = print_unsigned_integers(flags, ap);
	else if (c == 'x' || c == 'X')
	{
		returned = print_unsigned_hex(flags, ap);
		if (c == 'X')
			ft_touppercase(returned);
	}
	else
		returned = print_per_cent(flags);
	return (returned);
}

int		ft_is_conversion(int c)
{
	return (c == 'i' || c == 'd' || c == 's' || c == 'c' || c == 'p' ||
	c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int		ft_read_number(const char *str, va_list ap)
{
	long	nbr;

	nbr = 0;
	if (*str == '\0')
		return (0);
	if (*str == '*')
		nbr = (int)va_arg(ap, void *);
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*(str++) - '0');
		if ((nbr) > 2147483647)
			return (-1);
		if ((nbr) < -2147483648)
			return (0);
	}
	return (int)(nbr);
}

void	ft_scan_flag(t_flag *flag, char *str, int *i, va_list ap)
{
	int aux;

	aux = ft_read_number(str, ap);
	flag->active = 1;
	flag->number = aux;
	if (*str == '*')
	{
		*i = *i + 1;
		if(flag->number < 0)
		{
			flag->number = -aux;
			flag->star  = 1;
		}
	}
	while (ft_isdigit(*str++))
		*i = *i + 1;
}

int		print_variable(char *str, va_list ap, char **buff)
{
	t_list_flags	*flags;
	int				i;

	i = 0;
	flags = ft_calloc(sizeof(t_list_flags), 1);
	while (!ft_is_conversion(str[i]))
	{
		if (str[i] == '-')
			ft_scan_flag(&(flags->sign), &(str[++i]), &i, ap);
		else if (str[i] == '0')
			ft_scan_flag(&(flags->cero), &(str[++i]), &i, ap);
		else if (((str[i] >= '1' && str[i] <= '9') || str[i] == '*'))
			ft_scan_flag(&(flags->minimum), &(str[i]), &i, ap);
		else if (str[i] == '.')
			ft_scan_flag(&(flags->precision), &(str[++i]), &i, ap);
		else
			i++;
	}
	star_exceptions(flags);
	*buff = render_variable(str[i], *flags, ap);
	return (i);
}
