/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:48:43 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 13:38:56 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ini_var(int *i, int *j, int *flag)
{
	*i = 1;
	*j = 0;
	*flag = -1;
}

static char		*ini_print_ptr(int *i, int *j, int *flag, void *ptr)
{
	char *str;

	ini_var(i, j, flag);
	str = ini_str_ptr();
	str = (ptr == NULL ? ft_strdup("0x0") : str);
	return (str);
}

char			*print_pointer(t_list_flags flags, va_list ap)
{
	void	*ptr;
	char	*string;
	int		size;

	ptr = (void *)va_arg(ap, void *);
	string = ptr_to_str(ptr);
	string = apply_ceros_hex(flags.precision, string, 1);
	size = ft_strlen(string);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
	{
		if (!flags.precision.active)
			string = apply_ceros_hex(flags.cero, string, 0);
		else
			apply_spaces(&string, flags.minimum, size, 1);
	}
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}

char			*ptr_to_str(void *ptr)
{
	char			*str;
	unsigned char	*cast;
	int				i;
	int				j;
	int				flag;

	cast = (unsigned char *)&ptr;
	str = ini_print_ptr(&i, &j, &flag, ptr);
	while (j < 8)
	{
		if (flag >= 0 || ((cast[7 - j] >> 4) & 15) != 0)
		{
			flag = (flag == -1 ? 0 : flag);
			str[i * 2 + (flag == 0 ? 0 : -1)] = byte_to_hex((cast[7 - j] >> 4)
			& 15);
		}
		if ((flag >= 0 || (cast[7 - j] & 15) != 0))
		{
			flag = (flag == -1) ? 1 : flag;
			str[i * 2 + (flag == 1 ? 0 : 1)] = byte_to_hex(cast[7 - j] & 15);
			i++;
		}
		j++;
	}
	return (str);
}

char			*ini_str_ptr(void)
{
	char *str;

	str = ft_calloc(1, 18);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
