#include "header.h"

char	*printPointer(t_list_flags flags, va_list ap)
{
	void *ptr;
	char *string;
	int size;

	ptr = (void *)va_arg(ap, void *);
	string = ptrToStr(ptr);
	size = ft_strlen(string);
	if(flags.precision.active)
        string = applyCerosHex(flags.precision, string);
    size = ft_strlen(string);
    if(flags.sign.active)
        applySpaces(&string, flags.sign, size, 0);
    else if (flags.cero.active)
	{
		if(!flags.precision.active)
			string = applyCeros(flags.cero, string);
		else
			applySpaces(&string, flags.minimum, size, 1);
	}
    else if (flags.minimum.active)
        applySpaces(&string, flags.minimum, size, 1);
	
	return(string);
}

char *ptrToStr(void *ptr)
{
	char *str;
	unsigned char *cast;
	int		i;
	int		j;
	int flag;

	cast = (unsigned char *)&ptr;
	str = iniStrPtr();
	i = 1;
	j = 0;
	flag = 0;
	while(j < 8)
	{
		if(flag || (cast[7 - j] & 15) != 0)
		{
			str[i * 2] = byteToHex(cast[7 - j] & 15);
			flag = 1;
		}
		if(flag || ((cast[7 - j] >> 4) & 15) != 0)
		{
			str[i * 2 + 1] = byteToHex((cast[7 - j] >> 4) & 15);
			flag = 1;
			i++;
		}
		j++;
	}
	return(str);
}

char *iniStrPtr()
{
	char *str;

	str = ft_calloc(1, 18);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char byteToHex(char c)
{
	if(c < 10)
		return (c + '0');
	else if (c < 16)
		return (c +  'a' - 10);
	else
		return (0);
}