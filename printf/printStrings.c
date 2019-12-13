#include "header.h"

char		*printString(t_list_flags flags, va_list ap)
{
    char *string;
    char *cpy;
    int size;

    string = (char *)va_arg(ap, void *);
    string = ft_strdup(string);
    if(flags.precision.active)
    {
        cpy = string;
        string = ft_substr(string, 0, flags.precision.number);
        free(cpy);
    }
    size = ft_strlen(string);
    if(flags.sign.active)
        applySpaces(&string, flags.sign, size, 0);
    else if (flags.cero.active)
        string = applyCeros(flags.cero, string);
    else if (flags.minimum.active)
        applySpaces(&string, flags.minimum, size, 1);
    return (string);
}

