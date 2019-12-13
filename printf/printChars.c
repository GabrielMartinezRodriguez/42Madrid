#include "header.h"

char	*printChar(t_list_flags flags, va_list ap)
{
    char *string;
    char c;
    int size;

    size = 1;
    c = (char)va_arg(ap, void *);
    string = charToString(c);
     if(flags.sign.active)
        applySpaces(&string, flags.sign, size, 0);
    else if (flags.cero.active)
        string = applyCeros(flags.cero, string);
    else if (flags.minimum.active)
        applySpaces(&string, flags.minimum, size, 1);
    return (string);
}

char *charToString(char c)
{
    char *str;

    str = ft_calloc(1, 2);
    str[0] = c;
    return(str);
}