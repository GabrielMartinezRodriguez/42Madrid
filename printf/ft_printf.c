/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:32:16 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/12 21:01:28 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int main()
{
	//ft_printf("printf %*d\n",-838);
	ft_printf("fake printf %0100.89-100d\n",-8, 45);

}

char *renderVariable(char c, t_list_flags flags, va_list ap, char *buff)
{
	int integers;
	char *returned;
	char *cpy;
	if (c == 'i' || c == 'd')
		returned = printIntegers(flags, ap);
	returned = ft_strjoin(buff, returned);
	free(buff);
	return (returned);
}

int ft_isConversion(int c)
{
	return (c == 'i' || c == 'd' || c == 's');
}
int			ft_readNumber(const char *str, va_list ap) // debo cambiarlo
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
int ft_ScanFlag(t_flag *flag, char *str, int *i, va_list ap)
{
	int aux;

	aux = ft_readNumber(str, ap);
	if (aux != 0)
	{
		flag->active = 1;
		flag->number = aux;
	}
	if (*str == '*')
		*i = *i + 1;
	while (ft_isdigit(*str++))
		*i = *i + 1;
}
int printVariable(char *str, va_list ap, char **buff)
{
	t_list_flags	*flags;
	int				aux;
	int				i;

	i = 0;
	*buff = ft_calloc(1, 1);
	flags = ft_calloc(sizeof(t_list_flags), 1);
	while (!ft_isConversion(str[i]))
	{
		if (str[i] == '-') /*ESPACIO PARA DETECCION DE FLAGS - ORDENADO POR PRIORIDAD */
			ft_ScanFlag(&(flags->sign), &(str[++i]), &i, ap);
		else if (str[i] == '0')
			ft_ScanFlag(&(flags->cero), &(str[++i]), &i, ap);
		else if (((str[i] >= '1' && str[i] <= '9') || str[i] == '*' ))
			ft_ScanFlag(&(flags->minimum), &(str[i]), &i, ap);
		/* FLAG APLICABLES SIN SOBREESCRIBIR A LOS OTROS*/
		else if (str[i] == '.')
			ft_ScanFlag(&(flags->precision), &(str[++i]), &i, ap);
		else
			i++;
	}
	*buff = renderVariable(str[i], *flags, ap, *buff);
	return (i);
}



int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		charsN;
	int		len;
	char	*buff;

	va_start(ap, str);
	i = 0;
	charsN = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += printVariable(&(str[++i]), ap, &buff);
			len = ft_strlen(buff);
			write(1, buff, len);
			charsN += len;
		}
		else
		{
			write(1, &str[i], 1);
			charsN++;
		}
		i++;
	}
}
