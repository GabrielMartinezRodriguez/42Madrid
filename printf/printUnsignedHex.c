#include "header.h"

char	*printUnsignedHex(t_list_flags flags, va_list ap)
{
	unsigned int number;
	char			*string;
	int size;

	number = (unsigned int)va_arg(ap, void *);

	string = unsignedToHex(number);
	if(flags.precision.active)
		string  = applyCeros(flags.precision, string);
	size = ft_strlen(string);
	if(flags.sign.active)
		applySpaces(&string, flags.sign, size, 0);
	else if(flags.cero.active)
	{
		if(!flags.precision.active)
			string = applyCeros(flags.cero, string);
		else
			applySpaces(&string, flags.cero, size, 1);
	}
	else if(flags.minimum.active)
		applySpaces(&string, flags.minimum, size, 1);
	return(string);
}

char *unsignedToHex(unsigned int number)
{
	unsigned int cpy;
	unsigned int tam;
	unsigned int i;
	char		*string;

	tam = 0;
	cpy = number;
	if(cpy == 0)
		tam = 1;
	while(cpy > 0)
	{
		cpy /= 16;
		tam++;
	}
	string = ft_calloc(sizeof(char), tam + 1);
	i = 0;
	while(i < tam)
	{
		string[tam - i - 1] = byteToHex(number % 16);
		number /= 16;
		i++;
	}
	return(string);
}