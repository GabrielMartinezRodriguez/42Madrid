#include "header.h"

char	*printIntegers(t_list_flags flags, va_list ap)
{
	int		number;
	char	*str;
	int		size;

	number = (int)va_arg(ap, void *);
	str = ft_itoa((int)number);
	str = strCeros(flags.precision, str);
	size = ft_strlen(str);
	if(flags.sign.active)
		applySpaces(&str, flags.sign, size, 1);
	else if(flags.cero.active)
	{
		if(!flags.precision.active)
			str = strCeros(flags.cero, str);
		else
			applySpaces(&str, flags.cero, size, 0);
	}
	else if(flags.minimum.active)
		applySpaces(&str, flags.minimum, size, 0);
	return(str);
}

char	*strCeros(t_flag flag, char *str)
{
	int size;
	int			sign;
	char *ret;

	if(flag.active)
	{
		sign = 0;
		size = ft_strlen(str);
		size = flag.number - size;
		if(size > 0)
		{
			ret = malloc(sizeof(char) * (flag.number + 1));
			if(str[0] == '-')
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

