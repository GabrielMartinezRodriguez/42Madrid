#include "header.h"

char	*printUnsignedIntegers(t_list_flags flags, va_list ap)
{
    unsigned int number;
    char *string;
    int size;

    number = (unsigned int)va_arg(ap, void *);
    string = ft_itoaLong(number);
    string = strCeros(flags.precision, string);
	size = ft_strlen(string);
	if(flags.sign.active)
		applySpaces(&string, flags.sign, size, 0);
	else if(flags.cero.active)
	{
		if(!flags.precision.active)
			string = strCeros(flags.cero, string);
		else
			applySpaces(&string, flags.cero, size, 1);
	}
	else if(flags.minimum.active)
		applySpaces(&string, flags.minimum, size, 1);
	return(string);
}